class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int ans=0;
        int prev=0;

        int n=nums.size();
        int len=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1])len++;
            else{
                ans=max(ans,max(min(prev,len), max(prev,len)/2)) ;
                prev=len;
                len=1;
            }
        }
        ans=max(ans,max(min(prev,len), max(prev,len)/2)) ;
        return ans;
    }
};