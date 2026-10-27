class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid;
        string allClear(n,'.');
        string lastClear(n-1,'#');
        lastClear.push_back('.');
        for(int i=0;i<m;i++){
            if(i==0)grid.push_back(allClear);
            else grid.push_back(lastClear);
        }
        return grid;
    }
};