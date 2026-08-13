class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo=0,hi=nums.size()-1;
        int mini=INT_MAX;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            mini=min(mini,nums[mid]);
            if(nums[hi]<nums[mid]){
                lo=mid+1;
            }
            else if(nums[lo]>nums[mid]){
                hi=mid-1;
            }
            else hi=mid-1;

        }
        return mini;
    }
};