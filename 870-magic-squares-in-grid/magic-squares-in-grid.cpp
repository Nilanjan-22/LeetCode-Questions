class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int sumr1=0,sumr2=0,sumr3=0,sumc1=0,sumc2=0,sumc3=0,sumd1=0,sumd2=0;
        int ans=0;
        if(grid.size()<3 || grid[0].size()<3)return 0;
        for(int i=0;i<=grid.size()-3;i++){
            for(int j=0;j<=grid[0].size()-3;j++){
                set<int> st;
                bool f=false;
                sumr1=0,sumr2=0,sumr3=0,sumc1=0,sumc2=0,sumc3=0,sumd1=0,sumd2=0;
                for(int it1=i;it1<i+3;it1++){
                    for(int it2=j;it2<j+3;it2++){
                        if(grid[it1][it2]>9 || st.find(grid[it1][it2])!=st.end()){
                            f=true;
                            break;
                        }
                        else st.insert(grid[it1][it2]);
                    }
                }
                if(f)continue;
                sumr1=grid[i][j]+grid[i][j+1]+grid[i][j+2];
                sumr2=grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2];
                sumr3=grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];
                sumc1=grid[i][j]+grid[i+1][j]+grid[i+2][j];
                sumc2=grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1];
                sumc3=grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2];
                sumd1=grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
                sumd2=grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];

                if(sumr1==15 && sumr2==15 && sumr3==15 && sumc1==15 && sumc2==15 && sumc3==15 && sumd1==15 && sumd2==15)ans++;
            }
        }
        return ans;
    }
};