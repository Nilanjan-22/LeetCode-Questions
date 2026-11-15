class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long ans=0;
        long long mod=1e9+7;
        long long oddCnt=0, prev=-1, oddSub=0,eveSub=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2==1){
                oddCnt++;
                if(oddCnt%2==1)oddSub+=i-prev;
                else eveSub+=i-prev;
                prev=i;
            }
            
            if(oddCnt%2==1)ans+=oddSub;
            else ans+=eveSub;
            ans%=mod;
        }
        return ans;
    }
};