class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                int rem=(i+nums[i])%n;
                res[i]=nums[rem];
            }
            else if(nums[i]<0){
                int move=abs(nums[i])%n;
                int rem=(n+i-move)%n;
                res[i]=nums[rem];
            }
            else res[i]=nums[i];
        }
        return res;
    }
};