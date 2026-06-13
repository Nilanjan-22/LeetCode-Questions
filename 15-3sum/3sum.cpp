class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> allTriplets;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int j=i+1,k=n-1;
            int sumRequired=0-nums[i];
            while(j<k){
                if(nums[j]+nums[k]==sumRequired){
                    allTriplets.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(nums[j]+nums[k]<sumRequired){
                    j++;
                }
                else {
                    k--;
                }
                while(j<k && j>i+1 && nums[j]==nums[j-1])j++;
                while(j<k && k<n-1 && nums[k]==nums[k+1])k--;
            }
        }
        return allTriplets;
    }
};