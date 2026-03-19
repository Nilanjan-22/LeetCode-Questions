class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<pair<int,int>>> pref(n,vector<pair<int,int>>(m,{0,0}));
        int ans=0;
        if(grid[0][0]=='X')pref[0][0].first=1;
        else if(grid[0][0]=='Y')pref[0][0].second=1;
        for(int i=1;i<n;i++){
            pref[i][0]=pref[i-1][0];
            if(grid[i][0]=='X')pref[i][0].first++;
            else if(grid[i][0]=='Y')pref[i][0].second++;
            if(pref[i][0].first == pref[i][0].second && pref[i][0].first>0)ans++;
        }
        for(int i=1;i<m;i++){
            pref[0][i]=pref[0][i-1];
            if(grid[0][i]=='X')pref[0][i].first++;
            else if(grid[0][i]=='Y')pref[0][i].second++;
            if(pref[0][i].first == pref[0][i].second && pref[0][i].first>0)ans++;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                pref[i][j].first=pref[i][j-1].first+pref[i-1][j].first-pref[i-1][j-1].first;
                pref[i][j].second=pref[i][j-1].second+pref[i-1][j].second-pref[i-1][j-1].second;
                if(grid[i][j]=='X')pref[i][j].first++;
                else if(grid[i][j]=='Y')pref[i][j].second++;
                if(pref[i][j].first == pref[i][j].second && pref[i][j].first>0)ans++;
            }
        }
        return ans;
    }
};