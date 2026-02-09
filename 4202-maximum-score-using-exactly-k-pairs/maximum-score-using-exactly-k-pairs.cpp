class Solution {
public:
    vector<vector<vector<long long>>> dp;
    vector<int> n1,n2;
    int n,m;
    long long ans(int i, int j, int k){
        if(k==0)return 0;
        if(i>=n || j>=m || i+k>n || j+k>m )return -1e18;

        if(dp[i][j][k]!=-1e18)return dp[i][j][k];
        // long long res=-1e18;
        //pick none
        long long pn=ans(i+1,j+1,k);
        //pick both
        long long pb= (long long)n1[i]*(long long)n2[j] + ans(i+1,j+1,k-1);
        //skip j
        long long pi=ans(i,j+1,k);
        //skip i
        long long pj=ans(i+1,j,k);

        return dp[i][j][k]=max(pj,max(pb,max(pi,pn)));
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        n1=nums1;
        n2=nums2;
        n=n1.size();
        m=n2.size();
        dp.resize(n,vector<vector<long long>>(m,vector<long long>(k+1,-1e18)));
        return ans(0,0,k);

    }   
};