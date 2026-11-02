class Solution {
public:
    long long countCommas(long long n) {
        long long cnt=0;
        long long temp=3;
        while(n>=pow(10,temp)){
            cnt+=(n-pow(10,temp)+1);
            temp+=3;
        }
        return cnt;
    }
};