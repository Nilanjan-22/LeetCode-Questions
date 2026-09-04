class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> MaxMin(n,nums[0]);
        for(int i=1;i<n;i++){
            MaxMin[i] = max(MaxMin[i-1],nums[i]);
        }
        int mini=INT_MAX;
        int firstStable=-1;
        for(int i=n-1;i>=0;i--){
            mini = min(mini, nums[i]);
            MaxMin[i]-=mini;
            if(MaxMin[i]<=k)firstStable=i;
        }
        return firstStable;
    }
};