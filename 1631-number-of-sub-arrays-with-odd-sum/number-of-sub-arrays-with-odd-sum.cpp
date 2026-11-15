class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int oddSumCnt=0, eveSumCnt=1;
        long long ans=0, mod=1e9+7;
        long long sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum%2==0){
                eveSumCnt++;
                ans+=oddSumCnt;
            }
            else {
                oddSumCnt++;
                ans+=eveSumCnt;
            }
            ans%=mod;
        }
        return ans;
    }
};