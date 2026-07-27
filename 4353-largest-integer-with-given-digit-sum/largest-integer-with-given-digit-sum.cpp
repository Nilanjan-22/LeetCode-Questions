class Solution {
public:
    int largestInteger(int n, int s) {
        if(s>9*n)return -1;
        int ans=0;
        int nCopy=n;
        while(nCopy>0){
            int dig = min(s,9);
            ans*=10;
            ans+=dig;
            s-=dig;
            nCopy--;
        }
        return ans;
    }
};