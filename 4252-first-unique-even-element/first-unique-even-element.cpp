class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        vector<int> freq(101,0);
        for(int i=0;i<nums.size();i++)freq[nums[i]]++;

        for(int i=0;i<nums.size();i++){
            if(freq[nums[i]]==1 && nums[i]%2==0)return nums[i];
        }

        return -1;
    }
};