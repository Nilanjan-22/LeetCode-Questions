class Solution {
public:
    int solve(int st, string& s, int k, vector<int>& dp, vector<vector<int>>& palindromes){
        if(st+k>s.size())return 0;
        if(dp[st]!=-1)return dp[st];
        int en=-1;
        int ans=solve(st+1,s,k,dp,palindromes);
        for(int i=st+k-1;i<s.size();i++){
            if(palindromes[st][i]){
                en=i;
                break;
            }
        }
        if(en!=-1){
            ans=max(ans, 1+solve(en+1,s,k,dp,palindromes));
        }
        return dp[st]=ans;
    }
    int maxPalindromes(string s, int k) {
        int n=s.size();
        vector<int> dp(n+1,-1);
        vector<vector<int>> palindromes(n+1,vector<int>(n+1,0));
        for(int i=0;i<n;i++){
            int left=i,right=i;
            while(left>-1 && right<n && s[left]==s[right]){
                palindromes[left][right]=1;
                left--;
                right++;
            }

            left=i;
            right=i+1;
            while(left>-1 && right<n && s[left]==s[right]){
                palindromes[left][right]=1;
                left--;
                right++;
            }
            
        }
        return solve(0,s,k,dp,palindromes);
    }
};