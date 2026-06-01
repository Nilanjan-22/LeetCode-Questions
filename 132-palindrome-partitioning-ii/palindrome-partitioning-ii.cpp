class Solution {
public:
    bool isPalindrome(int st, int en,string& s){
        while(st<en){
            if(s[st]!=s[en])return false;
            st++;
            en--;
        }
        return true;
    }
    int solve(int i, string& s , vector<int>& dp){
        if(i>=s.size())return 0;
        if(dp[i]!=-1)return dp[i];

        int minCost=INT_MAX;
        for(int j=i;j<s.size();j++){
            if(isPalindrome(i,j,s))minCost=min(minCost, 1+solve(j+1,s,dp));
        }

        return dp[i]=minCost;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return solve(0,s,dp)-1;
    }
};