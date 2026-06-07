class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> elements, vis;
        int n = nums.size();
        for(int i=0;i<n;i++){
            elements.insert(nums[i]);
        }

        int longestSequence=0;

        for(int i=0;i<n;i++){
            int cnt=1;
            if(elements.find(nums[i]-1)!= elements.end() || vis.find(nums[i])!=vis.end())continue;
            else{
                int num=nums[i];
                vis.insert(num);
                while(elements.find(num+1)!=elements.end()){
                    num=num+1;
                    cnt++;
                }

                longestSequence=max(cnt, longestSequence);
            }
        }

        return longestSequence;
    }
};