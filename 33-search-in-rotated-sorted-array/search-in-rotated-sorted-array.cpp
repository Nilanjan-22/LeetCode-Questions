class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size()-1;
        int low=0,high=n;
        
        while(low<=high){
            int mid=(low+high)/2;

            if(nums[mid]==target)return mid;

            if(nums[low]>nums[mid]){
                if(target>=nums[low] || target<=nums[mid])high=mid-1;
                else low=mid+1;
            }
            else{
                if(target>=nums[low] && target<=nums[mid])high=mid-1;
                else low=mid+1;
            }
        }
        return -1;
    }
};