class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0,hi=nums.size()-1;

        while(lo<=hi){
            int mid=(lo+hi)/2;

            if(nums[mid]==target)return mid;
            else if(nums[mid]>target && nums[hi]<nums[mid] && target<=nums[hi])lo=mid+1;
            else if(nums[mid]>target)hi=mid-1;
            else if(nums[mid]<target && nums[lo]>nums[mid] && nums[lo]<=target)hi=mid-1;
            else lo=mid+1;
        }
        if(lo<0 || lo>nums.size()-1 || nums[lo]!=target)return -1;
        else return lo;
    }
};