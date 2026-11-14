class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        vector<int> prefSum(n+1,0);
        int minimumSubarraySum=INT_MAX;
        for(int i=0;i<n;i++){
            prefSum[i+1]=prefSum[i]+nums[i];
            int it=l;
            while(i+1-it>=0 && it<=r){
                int sum = prefSum[i+1]-prefSum[i+1-it];
                if(sum>0){
                    minimumSubarraySum=min(minimumSubarraySum,sum);
                }
                it++;
            }
        }
        return minimumSubarraySum == INT_MAX ? -1 : minimumSubarraySum;
    }
};