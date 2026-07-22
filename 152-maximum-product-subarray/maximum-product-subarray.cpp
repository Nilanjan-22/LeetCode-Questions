class Solution {
public:
    int maxProduct(vector<int>& nums){
        long long maxProd=INT_MIN;
        long long prefMul=1;
        long long suffMul=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(prefMul==0)prefMul=1;
            if(suffMul==0)suffMul=1;
            prefMul*=nums[i];
            suffMul*=nums[n-1-i];
            maxProd = max(maxProd , max(prefMul,suffMul));
        }
        return maxProd;

    }
};