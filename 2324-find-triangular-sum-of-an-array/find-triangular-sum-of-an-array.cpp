class Solution {
public:

    int triangularSum(vector<int>& nums) {
        vector<int> prev=nums;
        int n=prev.size();
        while(n>1){
            for(int i=0;i<n-1;i++){
                prev[i]=(prev[i]+prev[i+1])%10;
            }
            n--;
        }
        return prev[0]%10;
    }
};