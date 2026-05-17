class Solution {
public:
    int solve (int cur, string& s,vector<int>& dp){
        if(cur==s.size()) return 1;
        if(cur>s.size())return 0;
        if(dp[cur]!=-1)return dp[cur];
        int total=0;
        //take only one
        if(s[cur]!='0')total+=solve(cur+1,s,dp);

        //take two
        if(s[cur]!='0'&&cur<s.size()-1){
            if(s[cur]=='1' || (s[cur]=='2' && s[cur+1]<'7')){
                total+=solve(cur+2,s,dp);
            }
        }
            

        return dp[cur]=total;

    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return solve(0,s,dp);

    }
};