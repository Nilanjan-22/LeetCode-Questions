class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxi=-1, n=nums.size();
        vector<int> pref(n);
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            pref[i]=gcd(nums[i],maxi);
        }
        sort(pref.begin(),pref.end());
        int i=0, j=n-1;
        long long totalSum=0;
        while(i<j){
            totalSum+=gcd(pref[i],pref[j]);
            i++;
            j--;
        }
        return totalSum;
    }
};