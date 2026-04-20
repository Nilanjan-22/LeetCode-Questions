class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        queue<vector<int>> q; //i,j,col,time
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<int>> reached(n,vector<int>(m,1e9));

        for(int i=0;i<sources.size();i++){
            q.push({sources[i][0],sources[i][1],sources[i][2],0});
            reached[sources[i][0]][sources[i][1]]=0;
            ans[sources[i][0]][sources[i][1]]=sources[i][2];
        }

        vector<vector<int>> dir ={{1,0},{0,1},{-1,0},{0,-1}};

        while(!q.empty()){
            int i=q.front()[0],j=q.front()[1],col=q.front()[2],time=q.front()[3];
            q.pop();
            if(ans[i][j]!=col){
                continue;
            }
            for(auto it: dir){
                int ni=i+it[0],nj=j+it[1];
                if(ni>=0 && ni<n && nj>=0 && nj<m && reached[ni][nj]>time && ans[ni][nj]<col){
                    ans[ni][nj]=col;
                    reached[ni][nj]=time+1;
                    q.push({ni,nj,col,time+1});
                }
            }
        }

        return ans;



    }
};