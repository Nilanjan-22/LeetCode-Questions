class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans=0;
        int ls=INT_MAX;

        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]>ls){
                int parts;
                if(nums[i]%ls==0)parts=nums[i]/ls;
                else parts=(nums[i]/ls +1);
                ans+=parts-1;
                ls=nums[i]/parts;
            }
            else{
                ls=min(ls,nums[i]);
            }
        }
        return ans;
    }
};