class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int createLcp(int i, int j, string& s){
        if(i>=n || j>=n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];

        if(s[i]==s[j])return dp[i][j] = 1+createLcp(i+1,j+1,s);
        else return dp[i][j]=0;
    }
    string findTheString(vector<vector<int>>& lcp) {
        n=lcp.size();
        string ans(n,0);
        char ch='a';
        for(int i=0;i<n;i++){
            if(ans[i]!=0)continue;
            if(ch>'z')return "";
            for(int j=i;j<n;j++){
                if(lcp[i][j])ans[j]=ch;
            }
            ch++;
        }
        
        cout<<ans<<" ";
        dp.resize(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                createLcp(i,j,ans);
            }
        }
        if(dp==lcp)return ans;
        return "";

    }
};