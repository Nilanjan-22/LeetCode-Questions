class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {

        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i%2==0){
                    int mov=m-(k%m);
                    int fpos=(j+mov)%m;
                    if(mat[i][j]!=mat[i][fpos]){
                        return false;
                    }
                }
                else{
                    int fpos=(j+k)%m;
                    if(mat[i][j]!=mat[i][fpos]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};