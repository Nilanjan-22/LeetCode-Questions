class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=1;i<n+1;i++){
            if(n%i==0){
                int maxi=-1,mini,nmax;
                int changes;
                bool done=true;
                for(int j=0;j<n;j+=i){
                    changes=0;
                    nmax=-1,mini=INT_MAX;
                    for(int it=j;it<j+i;it++){
                        nmax=max(nmax,nums[it]);
                        mini=min(mini,nums[it]);
                        if(it<j+i-1 && nums[it]>nums[it+1]){
                            changes++;
                        }
                    }
                    if(changes>1 && i>2){
                        done=false;
                        break;
                    }
                    if(changes==1 && nums[j+i-1]>nums[j] && i>2){
                        done=false;
                        break;
                    }
                    if(maxi>mini){
                        done=false;
                        break;
                    }
                    maxi=nmax;
                }
                if(done)sum+=i;

            }
        }

        return sum;
    }
};