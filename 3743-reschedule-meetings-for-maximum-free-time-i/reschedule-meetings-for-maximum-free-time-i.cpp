class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> free;
        free.push_back(startTime[0]-0);
        int n=endTime.size();
        for(int i=1;i<n;i++){
            free.push_back(startTime[i]-endTime[i-1]);
        }
        free.push_back(eventTime-endTime[n-1]);

        //create a sliding window of k+1 length

        int i=0,j=0;
        int ans=0,sum=0;
        while(j<=k){
            sum+=free[j];
            j++;
        }
        ans=sum;

        while(j<=n){
            sum-=free[i];
            sum+=free[j];
            ans=max(sum,ans);
            i++;
            j++;
        }
        return ans;

    }
};