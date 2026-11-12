class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int longestInc=1, longestDec=1;
        int curLen=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>=nums[i+1]){
                curLen=1;
            }
            else{
                curLen++;
                longestInc=max(curLen, longestInc);
            }
        }
        curLen=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<=nums[i+1]){
                curLen=1;
            }
            else{
                curLen++;
                longestDec=max(curLen, longestDec);
            }
        }

        return max(longestInc,longestDec);

    }
};