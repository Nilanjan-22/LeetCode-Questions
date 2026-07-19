class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n==1)return s;
        if(n==2)return s+m;

        long long mul=(n-2)/2;
        long long ans = s+m;
        ans+=mul*(m-1);
        return ans;
    }
};