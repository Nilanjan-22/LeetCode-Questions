class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum=0;
        int n=grid.size(),m=grid[0].size();
        vector<vector<long long>> prefv(n,vector<long long>(m,0)), prefh(n,vector<long long>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=grid[i][j];
                prefh[i][j]=sum;
            }
        }
        sum=0;
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                sum+=grid[i][j];
                prefv[i][j]=sum;
            }
        }

        if(sum%2==1)return false;

        for(int i=0;i<n;i++){
            cout<<prefh[i][m-1]<<" ";
            if(prefh[i][m-1]==(sum/2))return true;
        }
        cout<<endl;

        for(int j=0;j<m;j++){
            cout<<prefv[n-1][j]<<" ";
            if(prefv[n-1][j]==(sum/2))return true;
        }
        cout<<endl;
        return false;
    }
};