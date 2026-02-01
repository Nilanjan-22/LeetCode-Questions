class Solution {
public:
    int minimumCost(vector<int>& nums) {
        vector<int>n=nums;
        sort(n.begin(),n.end());
        for(int i=0;i<3;i++){
            if(nums[0]==n[i])return n[0]+n[1]+n[2];
        }
        return n[0]+n[1]+nums[0];
    }
};