class Solution {
public:
    int solve(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
        if(i>=s1.size())return s2.size()-j;
        if(j>=s2.size())return s1.size()-i;

        if(dp[i][j]!=-1)return dp[i][j];

        int minDeletions=INT_MAX;

        if(s1[i]==s2[j])return dp[i][j]=solve(i+1,j+1,s1,s2,dp);

        minDeletions = min( minDeletions, 1+solve(i+1,j,s1,s2,dp));
        minDeletions= min( minDeletions, 1+solve(i,j+1,s1,s2,dp));

        return dp[i][j]= minDeletions;
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        return solve(0,0,word1,word2,dp);
    }
};
