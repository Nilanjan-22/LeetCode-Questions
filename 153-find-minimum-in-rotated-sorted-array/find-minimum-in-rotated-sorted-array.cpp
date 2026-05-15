class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int minimum=INT_MAX;
        while(low<=high){
            int mid=low + (high-low)/2;

            if(nums[high]>nums[mid]){
                minimum=min(nums[mid],minimum);
                high=mid-1;
            }
            else{
                minimum=min(nums[mid],minimum);
                low=mid+1;
            }

        }
        return minimum;
    }
};