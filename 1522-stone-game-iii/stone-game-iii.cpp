class Solution {
public:
    int scoreOfPlayer1(int i, vector<int>& stones, vector<int>& dp){
        int n=stones.size();
        if(i>=n)return 0;

        if(dp[i]!=INT_MIN)return dp[i];

        int maxScore=INT_MIN;
        maxScore = max(maxScore , stones[i]-scoreOfPlayer1(i+1,stones,dp));
        if(i<n-1){
            maxScore = max(maxScore , stones[i]+stones[i+1]-scoreOfPlayer1(i+2,stones,dp));
        }
        if(i<n-2){
            maxScore = max(maxScore , stones[i]+stones[i+1]+stones[i+2]-scoreOfPlayer1(i+3,stones,dp));
        }

        return dp[i]=maxScore;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> dp(n,INT_MIN);
        int score1 = scoreOfPlayer1(0,stoneValue,dp);
        if(score1>0)return "Alice";
        else if(score1==0)return "Tie";
        else return "Bob";
    }
};