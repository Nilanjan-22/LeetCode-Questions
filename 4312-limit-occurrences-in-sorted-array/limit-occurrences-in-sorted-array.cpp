class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        int prev=-1;
        int temp;
        for(int i=0;i<nums.size();i++){
            if(prev!=nums[i]){
                temp=k;
                prev=nums[i];
            }
            if(temp>0){
                temp--;
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};