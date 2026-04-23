class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> posOfEachNum;
        int n=nums.size();
        for(int i=0;i<n;i++){
            posOfEachNum[nums[i]].push_back(i);
        }

        vector<long long> distanceArray(n);

        vector<int> curNumArray;
        for(auto it: posOfEachNum){
            curNumArray = it.second;
            long long dist=0;
            int len = curNumArray.size();
            for(int i=1;i<len;i++){
                dist+=(long long)curNumArray[i]-(long long)curNumArray[0];
            }
            distanceArray[curNumArray[0]]=dist;
            long long change, leftCnt,rightCnt;
            for(int i=1;i<len;i++){
                change=curNumArray[i]-curNumArray[i-1];
                leftCnt=i;
                rightCnt = len-i;
                dist+=(leftCnt*change);
                dist-=(rightCnt*change);
                distanceArray[curNumArray[i]]=dist;
            }
        }

        return distanceArray;

    }
};