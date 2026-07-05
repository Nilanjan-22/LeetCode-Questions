class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{0,1},{1,1}};
    int ms=0;
    int mod=1e9+7;
    int findMaxSum(int i, int j, vector<string>& board, vector<vector<int>>& dp){
        int n=board.size(),m=board[0].size();
        if(i==n-1 && j==m-1)return 0;
        if(i>=n || j>=m || board[i][j]=='X')return -1e6;

        if(dp[i][j]!=-1)return dp[i][j];

        int maxSum=-1e6;
        for(auto d:dir){
            int ni=i+d.first, nj=j+d.second;
            if(ni>=0 && nj>=0 && ni<n && nj<m){
                int val=0;
                if(board[ni][nj]<='9'){
                    val=board[ni][nj]-'0';
                }
                maxSum=max(maxSum,val+findMaxSum(ni,nj,board,dp));
            }
        }
        return dp[i][j]=maxSum;
    }
    long long findCnt(int i, int j, int sum, vector<string>& board, vector<vector<vector<long long>>>& dp){
        int n=board.size(),m=board[0].size();
        if(i==n-1 && j==m-1 && sum==ms)return 1;
        else if(i>=n || j>=m || sum>ms)return 0;

        if(dp[i][j][sum]!=-1)return dp[i][j][sum];
        long long ways=0;
        for(auto d:dir){
            int ni=i+d.first, nj=j+d.second;
            if(ni>=0 && nj>=0 && ni<n && nj<m && board[ni][nj]!='X'){
                int val=0;
                if(board[ni][nj]<='9'){
                    val=board[ni][nj]-'0';
                }
                ways+=findCnt(ni,nj,sum+val,board,dp);
                ways%=mod;
            }
        }   
        return dp[i][j][sum]=ways%mod;

    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<int>> dp1(n,vector<int>(m,-1));

        int maxSum=findMaxSum(0,0,board,dp1);
        if(maxSum<0)return {0,0};
        ms=maxSum;
        vector<vector<vector<long long>>> dp2(n,vector<vector<long long>>(m,vector<long long>(maxSum+1,-1)));
        int ways=findCnt(0,0,0,board,dp2);
        return {maxSum,ways};

    }
};