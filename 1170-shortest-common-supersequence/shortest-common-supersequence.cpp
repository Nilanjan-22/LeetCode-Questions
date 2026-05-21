class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size(), m=str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
        if(dp[n][m]==0)return str1+str2;
        string longestCommonSub="";
        int i=n,j=m;
        while(i>=1 && j>=1){
            int left=-1,up=-1;
            if(j>1)left=dp[i][j-1];
            if(i>1)up=dp[i-1][j];
            
            if(dp[i][j]==0)break;
            if(dp[i][j]> left && dp[i][j]>up){
                longestCommonSub.push_back(str1[i-1]);
                i--;
                j--;
            }
            else if(left<up){
                i--;
            }
            else{
                j--;
            }
        }
        reverse(longestCommonSub.begin(),longestCommonSub.end());
        string shortestCommonSup="";
        int p1=0,p2=0,p3=0;
        while(p1<n || p2<m){
            bool match1=false,match2=false;
            if(p1<n){
                if(str1[p1]==longestCommonSub[p3])match1=true;
            }
            if(p2<m){
                if(str2[p2]==longestCommonSub[p3])match2=true;
            }

            if(match1 && match2){
                shortestCommonSup.push_back(str2[p2]);
                p1++;
                p2++;
                p3++;
            }
            if(!match1 && p1<n){
                shortestCommonSup.push_back(str1[p1]);
                p1++;
            }
            if(!match2 && p2<m){
                shortestCommonSup.push_back(str2[p2]);
                p2++;
            }
        }
        return shortestCommonSup;
    }
};