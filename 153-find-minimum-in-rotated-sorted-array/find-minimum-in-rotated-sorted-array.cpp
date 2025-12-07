class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo=0, hi=nums.size()-1;

        int mini=INT_MAX, r=0;
        while(lo<=hi){
            int mid=(lo+hi)/2;

            if(nums[mid]<mini){
                mini=nums[mid];
                r=mid;
            }

            if(nums[lo]>nums[hi]){
                if(nums[mid]<nums[hi])hi=mid-1;
                else lo=mid+1;
            }
            else{
                hi=mid-1;
            }

        }
        if(lo>-1 && lo<nums.size() && nums[lo]<mini){
            mini=nums[lo];
            r=lo;
        }

        return mini;
    }
};