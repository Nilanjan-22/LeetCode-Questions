class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])==mp.end())mp[nums[i]]=1;
            else ans.push_back(nums[i]);
        }

        mp.clear();
        return ans;
    }
};