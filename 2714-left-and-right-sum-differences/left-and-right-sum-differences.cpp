class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int rightSum=0,n=nums.size();
        for(auto it: nums)rightSum+=it;
        vector<int> sumArray(n);

        int leftSum=0;
        for(int i=0;i<n;i++){
            rightSum-=nums[i];
            sumArray[i] = abs(leftSum-rightSum);
            leftSum+=nums[i];
        }

        return sumArray;
    }
};