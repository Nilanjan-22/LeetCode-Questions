class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo=0,hi=nums.size()-1;

        while(lo<=hi){
            int mid=(lo+hi)/2;

            if(mid%2==0 && mid<nums.size()-1){
                if(nums[mid]!=nums[mid+1])hi=mid-1;
                else lo=mid+1;
            }
            else if(mid%2==0){
                lo=nums.size()-1;
                break;
            }
            else if(mid%2==1 && mid>0){
                if(nums[mid]==nums[mid-1])lo=mid+1;
                else hi=mid-1;
            }
            else{
                lo=0;
                break;
            }
            
        }
        return nums[lo];
    }
};