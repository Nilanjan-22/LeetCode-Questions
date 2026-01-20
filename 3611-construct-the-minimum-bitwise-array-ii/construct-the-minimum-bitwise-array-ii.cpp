class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int lc=-1;
            int temp=nums[i];
            while(temp%2==1){
                lc++;
                temp/=2;
            }
            if(lc==-1)ans[i]=-1;
            else ans[i]=nums[i]-(1<<lc);
        }
        return ans;
    }
};