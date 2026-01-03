class Solution {
public:
    int numOfWays(int n) {
        int m=1e9+7;
        long long a=6,b=6;  //a=pattern aba and b=abc
        //from aba pattern 3 aba pattern and 2 abc pattern can be taken
        //from abc pattern 2aba pattern and 2 abc pattern can be taken

        for(int i=2;i<n+1;i++){
            long long na=(a*3+b*2)%m;
            long long nb=(a*2+b*2)%m;

            a=na;
            b=nb;
        }
        return (a+b)%m;
    }
};