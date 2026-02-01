class Solution {
public:
    int finalElement(vector<int>& nums) {
        int s=nums.size()-1;
        return max(nums[0],nums[s]);
    }
};