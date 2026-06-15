class Solution {
public:
    int maxProfit(int i, vector<vector<int>>& jobs, vector<int>& dp){
        if(i>=jobs.size())return 0;
        if(dp[i]!=-1)return dp[i];

        int ntake=maxProfit(i+1,jobs,dp);
        vector<int> search = {jobs[i][1],0,0};
        int nextInd= lower_bound(jobs.begin(),jobs.end(),search) - jobs.begin();
        int take=jobs[i][2]+maxProfit(nextInd,jobs,dp);

        return dp[i]=max(ntake,take);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=profit.size();
        vector<vector<int>> jobs;
        for(int i=0;i<n;i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        vector<int> dp(n,-1);

        return maxProfit(0,jobs,dp);
    }
};