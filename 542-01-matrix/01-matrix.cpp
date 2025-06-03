class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0)continue;
                int top=m+n,left=m+n;

                if(j-1>=0)left=mat[i][j-1];
                if(i-1>=0)top=mat[i-1][j];

                mat[i][j]= min(left,top)+1;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(mat[i][j]==0)continue;
                int bot=m+n,right=m+n;

                if(j+1<m)right=mat[i][j+1];
                if(i+1<n)bot=mat[i+1][j];

                mat[i][j]= min(mat[i][j], min(right,bot)+1);
            }
        }
        return mat;
    }
};