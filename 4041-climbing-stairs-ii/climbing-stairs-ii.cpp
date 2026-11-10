class Solution {
public:
    long long costFunction(int i, vector<int>& costs, vector<long long>& dp){
        if(i==costs.size())return 0;
        if(dp[i]!=-1)return dp[i];

        //jump one
        long long j1 = costs[i]+1+costFunction(i+1,costs,dp);
        //jump two
        long long j2=LLONG_MAX;
        if(i+2<=costs.size()){
            j2 = costs[i+1]+4+costFunction(i+2,costs,dp);
        }
        //jump three
        long long j3=LLONG_MAX;
        if(i+3<=costs.size()){   
            j3 = costs[i+2]+9+costFunction(i+3,costs,dp);
        }

        return dp[i]=min(j1,min(j2,j3));
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n+1,-1);
        return costFunction(0,costs,dp);
    }
};