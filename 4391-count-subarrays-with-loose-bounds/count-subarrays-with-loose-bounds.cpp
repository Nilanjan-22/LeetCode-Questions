class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long totalSubarrays=0;
        int startInd=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxK || nums[i]<minK){
                long long n = i-startInd-1;
                totalSubarrays+=(n*(n+1LL))/2LL;
                startInd=i;
            }
        }
        long long n = nums.size()-startInd-1;
        totalSubarrays+=(n*(n+1LL))/2LL;
        return totalSubarrays;
    }
};