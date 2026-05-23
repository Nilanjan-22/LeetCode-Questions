class Solution {
public:
    bool check(vector<int>& nums) {
        int mismatch=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                mismatch++;
            }
            if(mismatch>1)return false;
        }

        if(mismatch==1 && nums[nums.size()-1]>nums[0])return false;
        return true;


    }
};