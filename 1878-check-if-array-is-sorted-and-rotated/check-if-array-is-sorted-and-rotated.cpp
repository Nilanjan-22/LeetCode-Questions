class Solution {
public:
    bool check(vector<int>& nums) {
        int mismatch=0,mismatchInd=-1,maxi=-1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                mismatch++;
                mismatchInd=i;
            }
            if(mismatch>1)return false;
            maxi=max(maxi,nums[i]);
        }

        if(mismatch==1 && (nums[mismatchInd]!=maxi || nums[nums.size()-1]>nums[0]))return false;
        return true;


    }
};