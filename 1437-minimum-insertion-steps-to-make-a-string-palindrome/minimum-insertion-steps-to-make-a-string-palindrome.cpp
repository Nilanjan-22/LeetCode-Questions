class Solution {
public:
    int solve(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
        if(i>=s1.size())return s2.size()-j;
        if(j>=s2.size())return s1.size()-i;

        if(dp[i][j]!=-1)return dp[i][j];

        int minInsertions=INT_MAX;

        if(s1[i]==s2[j])return dp[i][j]=solve(i+1,j+1,s1,s2,dp);

        minInsertions = min(minInsertions, 1+solve(i+1,j,s1,s2,dp));
        minInsertions= min(minInsertions, 1+solve(i,j+1,s1,s2,dp));

        return dp[i][j]=minInsertions;
    }
    int minInsertions(string s) {
        int n=s.size();
        string s2=s;
        reverse(s2.begin(),s2.end());
        vector<vector<int>> dp(n,vector<int>(n,-1));

        return solve(0,0,s,s2,dp)/2;
    }
};