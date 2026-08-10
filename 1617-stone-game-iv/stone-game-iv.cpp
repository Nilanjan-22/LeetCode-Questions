class Solution {
public:
    bool solve(int n, int turn, vector<vector<int>>& dp){
        if(n==0 && turn==1)return true;
        if(n==0)return false;
        if(dp[n][turn]!=-1)return dp[n][turn];
        bool pos;
        if(turn==0)pos=false;
        else pos=true;
        int maxSqr = sqrt(n);
        for(int i=1;i<=maxSqr;i++){
            if(turn==0){
                pos|=solve(n-(i*i),!turn,dp);
            }
            else{
                pos&=solve(n-(i*i),!turn,dp);
            }
        }
        return dp[n][turn]=pos;
    }
    bool winnerSquareGame(int n) {
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(n,0,dp);
    }
};