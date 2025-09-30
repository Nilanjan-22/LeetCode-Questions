class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sd=nums[i]+nums[j];
                ans+=max(0,(int)(upper_bound(nums.begin(),nums.end(),sd-1)-nums.begin())-j-1);
            }
        }
        return ans;
    }
};