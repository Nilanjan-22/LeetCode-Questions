class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long sum=0,squareSum=0;
        long long n=grid.size()*grid.size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                sum+=grid[i][j];
                squareSum+=pow(grid[i][j],2);
            }
        }
        long long sumOfN=(n*(n+1))/2;
        long long squareSumOfN = (n*(n+1LL)*(2LL*n+1LL))/6LL;

        //mis-rep
        int x= sumOfN-sum;
        //mis^2-rep^2 = (mis-rep)*(mis+rep)
        int y=(squareSumOfN-squareSum)/x; //mis+rep
        int mis=(x+y)/2;
        int rep=y-mis;
        return {rep,mis};

    }
};