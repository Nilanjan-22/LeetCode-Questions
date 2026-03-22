class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();
        vector<vector<int>> mat90(n,vector<int>(n)),mat180(n,vector<int>(n)),mat270(n,vector<int>(n));
        //rotate 90
        int st=n-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat90[j][st]=mat[i][j];
            }
            st--;
        }
        //rotate 180
        st=n-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat180[j][st]=mat90[i][j];
            }
            st--;
        }

        //rotate 270
        st=n-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat270[j][st]=mat180[i][j];
            }
            st--;
        }

        bool m0=true,m1=true,m2=true,m3=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(target[i][j]!=mat[i][j])m0=false;
                if(target[i][j]!=mat90[i][j])m1=false;
                if(target[i][j]!=mat180[i][j])m2=false;
                if(target[i][j]!=mat270[i][j])m3=false;
            }
        }
        return (m0|m1|m2|m3);


    }
};