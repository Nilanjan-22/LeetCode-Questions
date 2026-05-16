class Solution {
public:
    int findMin(vector<int>& nums) {
        int minimum=INT_MAX;
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid= low + (high-low)/2;

            if(nums[mid]>nums[high]){
                minimum=min(minimum, nums[mid]);
                low=mid+1;
            }
            else if(nums[mid]<nums[high]){
                minimum=min(minimum, nums[mid]);
                high=mid-1;
            }
            else{
                minimum=min(minimum, nums[mid]);
                high--;
            }
        }
        return minimum;
    }
};