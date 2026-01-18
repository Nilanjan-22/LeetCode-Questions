class Solution {
public:
    void print(vector<vector<int>>v){
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int ans=1,n=grid.size(),m=grid[0].size();
        vector<vector<int>> row_sum(n,vector<int>(m+1,0));
        vector<vector<int>> col_sum(n+1,vector<int>(m,0));
        for(int i=0;i<n;i++)row_sum[i][0]=0;
        for(int j=0;j<m;j++)col_sum[0][j]=0;

        for(int i=0;i<n;i++){
            for(int j=1;j<m+1;j++){
                row_sum[i][j]=grid[i][j-1]+row_sum[i][j-1];
            }
        }
        for(int j=0;j<m;j++){
            for(int i=1;i<n+1;i++){
                col_sum[i][j]=grid[i-1][j]+col_sum[i-1][j];
            }
        }

        for(int k=min(n,m); k>1;k--){
            for(int r=0;r<=n-k;r++){
                for(int c=0;c<=m-k;c++){
                    long long target=row_sum[r][c+k]-row_sum[r][c];
                    bool pos=true;

                    for(int i=0;i<k;i++){
                        if(row_sum[r+i][c+k]-row_sum[r+i][c]!=target){
                            pos=false;
                            break;
                        }
                    }

                    if(!pos)continue;

                    for(int j=0;j<k;j++){
                        if(col_sum[r+k][c+j]-col_sum[r][c+j]!=target){
                            pos=false;
                            break;
                        }
                    }

                    if(!pos)break;

                    long long ds1=0,ds2=0;
                    for(int i=0;i<k;i++){
                        ds1+=grid[r+i][c+i];
                        ds2+=grid[r+i][c+k-i-1];
                    }

                    if(ds1==ds2 && ds1==target)return k;
                } 
            }
        }
        // print(row_sum);
        // cout<<endl;
        // print(col_sum);
        return 1;

    }
};