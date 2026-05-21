class Solution {
public:
    int solve(int i, int j, string& word1, string& word2, vector<vector<int>>& dp){
        if(i<0){
            if(j<0)return 0;
            return j+1;
        }
        if(j<0)return i+1;

        if(dp[i][j]!=-1)return dp[i][j];

        int minOps=INT_MAX;
        //character matched
        if(word1[i]==word2[j])return dp[i][j]=solve(i-1,j-1,word1,word2,dp);

        //insert
        minOps=min(minOps,1+solve(i,j-1,word1,word2,dp));

        //delete
        minOps=min(minOps, 1+solve(i-1,j,word1,word2,dp));

        //replace
        minOps=min(minOps,1+solve(i-1,j-1,word1,word2,dp));

        return dp[i][j]=minOps;

    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,word1,word2,dp);
    }  
};