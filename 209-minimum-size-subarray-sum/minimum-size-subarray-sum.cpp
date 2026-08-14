class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int sum=0;
        int st=0,en=0;

        while(en<nums.size()){
            sum+=nums[en];
            while(sum>=target+nums[st]){
                sum-=nums[st];
                st++;
            }
            if(sum>=target)minLen=min(en-st+1, minLen);
            en++;
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};