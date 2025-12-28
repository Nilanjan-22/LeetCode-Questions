class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n=nums.size()-1;
        long long sum=0;
        long long mini=nums[n];
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        long long ans=LLONG_MIN;

        for(int i=n-1; i>=0; i--){
            ans=max(sum-mini, ans);
            mini=min((int)mini,nums[i]);
            sum-=nums[i];
        }
        return ans;

        
    }
};