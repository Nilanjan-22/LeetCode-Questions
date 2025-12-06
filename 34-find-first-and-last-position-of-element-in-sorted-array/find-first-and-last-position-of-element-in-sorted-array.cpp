class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0)return {-1,-1};
        int lo=0,hi=nums.size()-1;
        vector<int> ans;
        while(lo<=hi){
            int mid=(lo+hi)/2;

            if(nums[mid]<target)lo=mid+1;
            else hi=mid-1;
        }
        
        if(lo<0 || lo>=nums.size() || nums[lo]!=target)return {-1,-1};
        else ans.push_back(lo);

        lo=0,hi=nums.size()-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;

            if(nums[mid]<=target)lo=mid+1;
            else hi=mid-1;
        }
        ans.push_back(hi);
        return ans;
    }
};