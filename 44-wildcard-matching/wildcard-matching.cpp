class Solution {
public:
    bool solve(int i, int j, string&s, string& p , vector<vector<int>>& dp){
        if(i>=s.size() && j>=p.size())return true;
        if(j>=p.size())return false;
        if(i==s.size()){
            for(int it=j;it<p.size();it++){
                if(p[it]!='*')return false;
            }
            return true;
        }

        if(dp[i][j]!=-1)return dp[i][j];

        bool possible=false;
        if(p[j]=='*'){
            possible |= solve(i+1,j,s,p,dp);
            possible |= solve(i+1,j+1,s,p,dp);
            possible |= solve(i,j+1,s,p,dp);
        }
        if(p[j]=='?' || p[j]==s[i]){
            possible |= solve(i+1,j+1,s,p,dp);
        }
        return dp[i][j]=possible;
        
    }
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,s,p,dp);
    }
};