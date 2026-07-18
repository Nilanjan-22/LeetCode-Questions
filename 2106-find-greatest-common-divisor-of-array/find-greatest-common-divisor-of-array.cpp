class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi=INT_MIN,mini=INT_MAX;

        for(auto it: nums){
            maxi=max(maxi,it);
            mini=min(mini,it);
        }
        return gcd(maxi,mini);
    }
};