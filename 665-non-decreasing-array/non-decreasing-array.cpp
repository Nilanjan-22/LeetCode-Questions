class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int mismatch=0, prev=-1, next=-1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                mismatch++;
                prev=i;
                next=i+2;
            }
        }
        if(mismatch>1)return false;
        if(mismatch==0 || prev==0 || prev==nums.size()-2)return true;
        if(nums[prev]<=nums[next] || nums[prev-1]<=nums[next-1])return true;
        return false;
    }
};