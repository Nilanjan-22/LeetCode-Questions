class Solution {
public:
    int maxProduct(vector<int>& nums){

        int n=nums.size();
        long long maxi=INT_MIN;
        for(int i=0;i<n;i++){
            long long prod=nums[i];
            maxi= max(maxi,prod);
            for(int j=i+1;j<n;j++){
               prod*=nums[j];
               maxi=max(prod,maxi);
            }
        }

        return (int)maxi;
    }
};