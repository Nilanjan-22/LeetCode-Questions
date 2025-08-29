class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans=0;
        long long ev=n/2, od=(n+1)/2;
        ans+= ev*(long long)((m+1)/2);
        ans+=od*(long long)(m/2);
        // for(int i=1;i<=n;i++){
        //     if(i%2==0)ans+=(m+1)/2;
        //     else ans+=m/2;
        // }
        return ans;
    }
};