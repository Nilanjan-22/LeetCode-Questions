class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        vector<vector<int>> vec; //store start,end,(up[1] or down[0]);
        int n=nums.size();
        vector<long long> pref(n+1,0);
        int start=0,turn=-1;
        nums.push_back(-1e9-1);
        for(int i=0;i<n;i++){
            pref[i+1]=(long long)nums[i]+pref[i];
            if(nums[i]==nums[i+1]){
                if(start!=i){
                    vec.push_back({start,i,turn});
                }
                start=i+1;
                turn=-1;
            }
            else if(nums[i]<nums[i+1] && turn==-1){
                turn=1;
            }
            else if(nums[i]>nums[i+1] && turn==-1)turn=0;
            else if(turn==1 && nums[i]>nums[i+1]){
                if(start==i){
                    turn=-1;
                    continue;
                }
                vec.push_back({start,i,turn});
                turn=0;
                start=i;
            }
            else if(turn==0 && nums[i]<nums[i+1]){
                if(start==i){
                    turn=-1;
                    continue;
                }
                vec.push_back({start,i,turn});
                turn=1;
                start=i;
            }
        }

        for(int i=0;i<vec.size();i++){
            cout<<vec[i][0]<<" "<<vec[i][1]<<" "<<vec[i][2]<<endl;
        }

        long long maxsum=-1e18;
        turn=1;
        int end=-1;
        long long sum=0;
        for(int i=0;i<vec.size();i++){
            if(end==-1 && vec[i][2]!=turn)continue;
            if((end!=-1 && end!=vec[i][0]) || turn!=vec[i][2]){
                if(vec[i][2]==1)i--;
                sum=0;
                end=-1;
                turn=1;
                continue;
            }
            else if(turn==vec[i][2]){
                if(end==-1){
                    int it=vec[i][0];
                    while(it<vec[i][1]-1){
                        if(nums[it]>0)sum+=(long long)nums[it];
                        it++;
                    }
                    sum+=nums[it];
                    turn=0;
                    end=vec[i][1];
                }
                else{
                    if(turn==0){
                        sum+=pref[vec[i][1]]-pref[vec[i][0]];
                        turn=1;
                        end=vec[i][1];
                    }
                    else{
                        long long comp=nums[vec[i][0]]+nums[vec[i][0]+1];
                        if(pref[vec[i][1]+1]-pref[vec[i][0]]<comp)sum+=comp;
                        else sum+=pref[vec[i][1]+1]-pref[vec[i][0]];
                        maxsum=max(maxsum,sum);
                        sum=0;
                        end=-1;
                        turn=1;
                        i--;
                    }
                }
            }
        }


        return maxsum;
    }
};