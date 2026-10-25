class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int peakSum=0, valleySum=0;
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]>max(nums[i-1], nums[i+1]))peakSum+=nums[i];
            if(nums[i]<min(nums[i-1],nums[i+1]))valleySum+=nums[i];
        }
        return peakSum-valleySum;
    }
};