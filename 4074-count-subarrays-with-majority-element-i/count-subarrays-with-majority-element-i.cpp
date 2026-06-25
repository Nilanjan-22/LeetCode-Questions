class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int cnt=0;
        vector<int> cntOfTarget(n+1,0);
        for(int i=0;i<n;i++){
            cntOfTarget[i+1]=cntOfTarget[i];
            if(nums[i]==target)cntOfTarget[i+1]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(cntOfTarget[j+1]-cntOfTarget[i] > (j-i+1)/2)ans++;
            }
        }
        return ans;
    }
};