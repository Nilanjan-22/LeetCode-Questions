class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(nums[i],maxi);
        }
        int ans=1;
        int consi=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi){
                consi++;
                ans=max(ans,consi);
            }
            else consi=0;
        }
        return ans;
    }
};