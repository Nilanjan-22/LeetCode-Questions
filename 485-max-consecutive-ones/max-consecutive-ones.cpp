class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int consecutiveOnes=0;
        int cnt=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]!=1){
                cnt=0;
            }
            else{
                cnt++;
                consecutiveOnes=max(consecutiveOnes,cnt);
            }
        }
        return consecutiveOnes;
    }
};