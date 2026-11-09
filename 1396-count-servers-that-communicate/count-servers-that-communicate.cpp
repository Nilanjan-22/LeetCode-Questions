class Solution {
public:
    
    int countServers(vector<vector<int>>& grid) {
        map<int,int> rowCnt, colCnt;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    rowCnt[i]++;
                    colCnt[j]++;
                }
            }
        }

        int communicatingServers=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    if(rowCnt[i]>1 || colCnt[j]>1)communicatingServers++;
                }
            }
        }
        return communicatingServers;
    }
};