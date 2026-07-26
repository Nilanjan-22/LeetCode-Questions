class Solution {
public:
    int solve(int i, vector<vector<int>>& jobs, vector<int>& dp){
        if(i>=jobs.size())return 0;
        if(dp[i]!=-1)return dp[i];

        int maxProfit=0;
        //take
        int nextInd = lower_bound(jobs.begin(),jobs.end(),vector<int>{jobs[i][1],0,0}) - jobs.begin();
        maxProfit = max(maxProfit, jobs[i][2]+solve(nextInd,jobs,dp));
        //notTake
        maxProfit = max(maxProfit, solve(i+1,jobs,dp));

        return dp[i]=maxProfit;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        int n=profit.size();
        for(int i=0;i<n;i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        vector<int> dp(n,-1);
        return solve(0,jobs,dp);
    }
};