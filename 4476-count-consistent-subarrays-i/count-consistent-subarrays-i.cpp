class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int mini=INT_MAX, andOfEl=INT_MAX;
            for(int j=i;j<nums.size();j++){
                mini=min(mini,nums[j]);
                andOfEl&=nums[j];
                if(andOfEl==mini)cnt++;
            }
        }
        return cnt;
    }
};