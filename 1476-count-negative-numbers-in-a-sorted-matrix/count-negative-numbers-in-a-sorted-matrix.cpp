class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;

        int r=grid.size()-1,c=0, cmax=grid[0].size();

        while(r>=0){
            while(c<cmax && grid[r][c]>=0){
                c++;
            }
            if(c==cmax)break;
            else{
                ans+=cmax-c;
                r--;
            }
        }
        return ans;
    }
};