class Solution {
public:
    pair<double,double> pos(double y, vector<vector<int>>& squares){
        double sum1=0,sum=0;
        for(int i=0;i<squares.size();i++){
            double yt=squares[i][1], l=squares[i][2];
            if(yt+l<=y)sum1+=(l*l);
            else if(y>=yt && y<=yt+l){
                double h1=y-yt;
                sum1+=(h1*l);
            }
            sum+=l*l;
        }
        cout<<sum1<<" "<<sum/2.0<<" "<<y<<endl;
        return {sum1,sum/2.0};
    }
    double separateSquares(vector<vector<int>>& squares) {
        double low=0,high=1e9;
        double ans=-1;
        while((high-low)>1e-5){
            double mid=low+(high-low)/2.0;
            pair<double,double> s=pos(mid,squares);
            double sum1=s.first;
            double hsum=s.second;
            if(abs(sum1-hsum)<double(1e-1)){
                cout<<abs(sum1-hsum)<<endl;
                ans=mid;
            }
            if(sum1>=hsum)high=mid;
            else low=mid;
        }
        return high;
    }
};