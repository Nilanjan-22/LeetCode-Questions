class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n-k+1);
        map<int,int> mp;
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
        }
        for(int i=0;i<n-k+1;i++){
            int maxNum=mp.rbegin()->first;
            ans[i]=maxNum;
            mp[nums[i]]--;
            if(mp[nums[i]]==0)mp.erase(nums[i]);
            if(i+k<n)mp[nums[i+k]]++;
        }
        return ans;
    }
};