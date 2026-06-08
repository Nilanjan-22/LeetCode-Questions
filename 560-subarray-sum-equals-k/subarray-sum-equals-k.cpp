class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> sumCnt; 
        int totalSubarray=0;
        sumCnt[0]=1;
        int sumSoFar=0;
        for(int i=0;i<nums.size();i++){
            sumSoFar+=nums[i];
            if(sumCnt.find(sumSoFar-k)!=sumCnt.end())totalSubarray+=sumCnt[sumSoFar-k];
            sumCnt[sumSoFar]++;
        }
        return totalSubarray;
    }
};