class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int x=0;
            bool found=false;
            while(x<nums[i]){
                int m=x|(x+1);
                if(m==nums[i]){
                    ans[i]=x;
                    found=true;
                    break;
                }
                x++;
            }
            if(!found)ans[i]=-1;
        }
        return ans;
    }
};