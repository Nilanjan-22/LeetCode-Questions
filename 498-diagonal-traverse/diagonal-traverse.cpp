class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        vector<int> ans;

        int it=0;
        int dir=1; //0 up to down , 1 means down to up
        int i=0,j=0;
        while(it<m*n){
            if(dir==0){
                while(i<m && j>=0){
                    ans.push_back(mat[i][j]);
                    i++;
                    j--;
                    it++;
                }
                if(j<0 && i<m){
                    j=0;
                }
                else if(i>=m){
                    i--;
                    j+=2;
                }
                dir=1;
            }
            else if(dir==1){
                while(j<n && i>=0){
                    ans.push_back(mat[i][j]);
                    j++;
                    i--;
                    it++;
                }
                if(i<0 && j<n){
                    i=0;
                }
                else if(j>=n){
                    i+=2;
                    j--;
                }
                dir=0;
            }

        }
        return ans;

    }
};