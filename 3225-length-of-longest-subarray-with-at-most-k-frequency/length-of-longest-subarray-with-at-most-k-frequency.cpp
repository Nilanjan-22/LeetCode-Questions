class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int st=0,en=0;
        int maxSubarrayLen=-1;
        unordered_map<int,int> hash;
        while(en<nums.size()){
            hash[nums[en]]++;
            while(hash[nums[en]]>k){
                hash[nums[st]]--;
                st++;
            }
            maxSubarrayLen=max(maxSubarrayLen, en-st+1);
            en++;
        }
        return maxSubarrayLen;
    }
};