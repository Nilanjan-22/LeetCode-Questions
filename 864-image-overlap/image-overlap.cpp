class Solution {
public:
    int matches(int i, int j, vector<vector<int>>& img1, vector<vector<int>>& extendedImg){
        int n=img1.size();
        int matchCnt=0;
        for(int i1=0; i1<n;i1++){
            for(int j1=0;j1<n;j1++){
                if(img1[i1][j1] == extendedImg[i+i1][j+j1] && img1[i1][j1]==1)matchCnt++;
            }
        }
        return matchCnt;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<vector<int>> extendedImg(3*n-2,vector<int>(3*n-2,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                extendedImg[n+i-1][n+j-1]=img2[i][j];
            }
        }

        int largestOv=0;
        for(int i=0;i<2*n-1;i++){
            for(int j=0;j<2*n-1;j++){
                largestOv = max(largestOv, matches(i,j,img1,extendedImg));
            }
        }

        return largestOv;
    }
};