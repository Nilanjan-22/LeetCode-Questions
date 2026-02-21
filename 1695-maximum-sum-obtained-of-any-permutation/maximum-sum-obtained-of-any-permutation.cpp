class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int m=1e9+7;
        map<int,int> events;
        for(int i=0;i<requests.size();i++){
            int st=requests[i][0],en=requests[i][1];
            events[st]++;
            events[en+1]--;
        }
        map<int,int> times;
        int sum=0;
        int st=-1;
        for(auto it:events){
            if(sum>0){
                times[sum]+=(it.first-st);
            }
            sum+=it.second;
            st=it.first;
        }

        sort(nums.rbegin(),nums.rend());
        
        long long ans=0;
        int i=0;
        for(auto it=times.rbegin();it!=times.rend();it++){
            int v=it->first;
            int t=it->second;
            cout<<v<<" "<<t;
            for(int j=0;j<t;j++){
                ans+=(long long)v*(long long)nums[i];
                i++;
                ans%=m;
            }
        }

        return ans;

    }
};