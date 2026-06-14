class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int unique=0;
        int prev=101;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==prev){
                nums[i]=101;
            }
            else {
                unique++;
                prev=nums[i];
            }
        }
        sort(nums.begin(),nums.end());
        return unique;
    }
};