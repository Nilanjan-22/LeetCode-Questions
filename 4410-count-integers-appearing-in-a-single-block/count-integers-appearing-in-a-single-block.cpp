class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int> isSpecial(101,-1);
        isSpecial[nums[0]]=1;
        int ans=1;
        for(int i=1;i<n;i++){
            if(isSpecial[nums[i]]==1 && nums[i]!=nums[i-1]){
                isSpecial[nums[i]]=0;
                ans--;
            }
            else if(nums[i]!=nums[i-1] && isSpecial[nums[i]]==-1){
                isSpecial[nums[i]]=1;
                ans++;
            }
        }
        return ans;
    }
};