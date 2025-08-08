class Solution {
public:
    double ans(int a,int b, vector<vector<double>>& dp){
        if(a<=0 && b>0)return (double)0.25000;
        else if(a<=0 && b<=0)return (double)0.12500;
        else if(b<=0) return 0;

        if(dp[a][b]!=-1)return dp[a][b];
        //do first job
        double first= (ans(a-4,b,dp));
        //do second job
        double second=(ans(a-3,b-1,dp));
        //do third
        double third=(ans(a-2,b-2,dp));
        //do fourth
        double fourth=(ans(a-1,b-3,dp));

        return dp[a][b]=0.25*(first+second+third+fourth);
    }
    double soupServings(int n) {
        if(n>4450)return 1;
        vector<vector<double>> dp((n+24)/25 +1,vector<double>((n+24)/25 +1,-1));
        return 4*ans((n+24)/25,(n+24)/25,dp);
    }
};