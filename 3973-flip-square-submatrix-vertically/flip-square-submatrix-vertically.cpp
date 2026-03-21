class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int xs=x,xe=x+k-1, ys=y,ye=y+k-1;

        int l=xs, h=xe;
        while(l<=h){
            for(int i=ys;i<=ye;i++){
                swap(grid[l][i],grid[h][i]);
            }
            l++;
            h--;
        }

        return grid;
    }
};