class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int prev=-1,ans=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==prev)continue;
            else{
                long long mul=(long long)nums[i]*(long long)k;
                if(mul>1e9)mul=1e9;
                auto it = upper_bound(nums.begin(),nums.end(),mul);
                int rem1= nums.size() -(int)(it-nums.begin());
                int rem2=i;
                ans=min(ans,rem1+rem2);
                prev=nums[i];
            }
        }
        return ans;

    }
};