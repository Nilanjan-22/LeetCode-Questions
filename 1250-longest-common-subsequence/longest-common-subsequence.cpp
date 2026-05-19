class Solution {
public:
    int solve(int pos1, int pos2, string& s1, string& s2, vector<vector<int>>& dp){
        if(pos1>=s1.size() || pos2>=s2.size())return 0;

        if(dp[pos1][pos2]!=-1)return dp[pos1][pos2];

        if(s1[pos1]==s2[pos2])return dp[pos1][pos2]=1+solve(pos1+1,pos2+1,s1,s2,dp);

        int maxLength=0;

        maxLength=max(maxLength, solve(pos1+1,pos2,s1,s2,dp));
        maxLength=max(maxLength, solve(pos1,pos2+1,s1,s2,dp));


        return dp[pos1][pos2]=maxLength;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        return solve(0,0,text1,text2,dp);
    }
};