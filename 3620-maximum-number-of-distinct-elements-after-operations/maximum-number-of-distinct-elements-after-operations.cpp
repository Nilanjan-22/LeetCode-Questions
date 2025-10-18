class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();

        sort(nums.begin(),nums.end());

        map<int,pair<int,int>> mp;
        int prev=nums[0];
        for(int i=0;i<n;i++){
            if(prev!=nums[i]){
                mp[prev].second=nums[i];
                prev=nums[i];
            }
            mp[nums[i]].first++;
        }
        mp[nums[n-1]].second=INT_MAX-1e5;

        int ll=INT_MIN+1e5+1;

        for(auto it: mp){
            int ul=it.second.second-1;
            int cnt=it.second.first;
            int num=it.first;
            cout<<num<<" "<<cnt<<" "<<ul<<endl;
            if(num>ll){
                int minus=min(k,min(cnt,num-ll));
                cnt-=minus;
                ans+=minus;
                if(cnt==0){
                    ll=num-min(k,num-ll)+minus;
                }

            }
            if(cnt>=1 && num>=ll){
                ans++;
                cnt--;
                ll=num+1;
            }

            if(cnt>0){
                int plus=min(num+k-ll+1,cnt);
                ans+=plus;
                
                ll=ll+plus;
            }
        }
        return ans;
    }
};