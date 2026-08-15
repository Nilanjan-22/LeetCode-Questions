class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr=0;
        bool allZero=true;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0)allZero=false;
            xr^=nums[i];
        }
        if(allZero)return 0;
        
        return xr==0 ? nums.size()-1 : nums.size();
    }
};