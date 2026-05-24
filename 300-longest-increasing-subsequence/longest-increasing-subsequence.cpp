class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for(int i=0;i<nums.size();i++){
            if(lis.size()==0 || lis.back()<nums[i])lis.push_back(nums[i]);
            else{
                int ind= lower_bound(lis.begin(),lis.end(),nums[i])-lis.begin();
                lis[ind]=nums[i];
            }
        }

        return lis.size();
    }
};