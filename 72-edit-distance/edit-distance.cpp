class Solution {
public:
    int solve(int i,int j, string& w1, string& w2, vector<vector<int>>& dp){
        if(i>=w1.size())return w2.size()-j;
        if(j>=w2.size())return w1.size()-i;

        if(dp[i][j]!=-1)return dp[i][j];

        int minSteps=0;
        if(w1[i]==w2[j]){
            return dp[i][j]=solve(i+1,j+1,w1,w2,dp);
        }
        else{
            minSteps= 1+min(solve(i+1,j,w1,w2,dp),min(solve(i,j+1,w1,w2,dp), solve(i+1,j+1,w1,w2,dp)));
        }
        return dp[i][j]=minSteps;
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(), m=word2.size();
        if(n==0)return m;
        if(m==0)return n;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,word1,word2,dp);
    }
};