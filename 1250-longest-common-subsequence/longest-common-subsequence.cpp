class Solution {
public:
    int LCS(int i ,  int j, string& s1, string& s2, vector<vector<int>>& dp){
        if(i>=s1.size() || j>=s2.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];

        int maxLen=0;
        if(s1[i]==s2[j])maxLen = max(maxLen, 1+LCS(i+1,j+1,s1,s2,dp));
        else{
            maxLen=max(maxLen , LCS(i+1,j,s1,s2,dp));
            maxLen=max(maxLen, LCS(i,j+1,s1,s2,dp));
        }
        return dp[i][j]=maxLen;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return LCS(0,0,text1,text2,dp);
    }
};