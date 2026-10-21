class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        int r=0,c=0;
        int ansr=-1,ansc=-1;
        while( r<n && r>=0 && c<m && c>=0 && vis[r][c]!=1){
            vis[r][c]=1;
            ansr=r;
            ansc=c;
            if(grid[r][c]=='R'){
                c++;
            }
            else if(grid[r][c]=='L'){
                c--;
            }
            else if(grid[r][c]=='U'){
                r--;
            }
            else r++;
        }
        return {ansr,ansc};
    }
};