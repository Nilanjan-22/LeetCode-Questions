class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        unordered_set<int> hash;
        for(int i=0;i<nums.size();i++){
            hash.insert(nums[i]);
        }

        int longestLen=1;
        unordered_set<int> vis;
        for(int i=0;i<nums.size();i++){
            if(hash.find(nums[i]-1)!=hash.end() || vis.find(nums[i])!=vis.end())continue;
            int num=nums[i];
            vis.insert(num);
            int len=1;
            while(hash.find(num+1)!=hash.end()){
                num++;
                len++;
            }
            longestLen=max(len,longestLen);
        }

        return longestLen;
    }
};