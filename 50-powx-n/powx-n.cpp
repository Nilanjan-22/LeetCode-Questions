class Solution {
public:
    double myPow(double x, int n) {
        long long p =n;
        if(n==0 || x==1)return 1;
        if(n<0){
            x=1/x;
            p=abs(p);
        }
        double powerVal=1;
        while(p>0){
            double val=x;
            long long doubling = log2(p);
            p-=1LL<<doubling;
            while(doubling>0){
                val*=val;
                doubling--;
            }
            powerVal*=val;
        }
        return powerVal;
    }
};