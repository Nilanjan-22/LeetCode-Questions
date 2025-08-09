class Solution {
public:
    bool isPowerOfTwo(int n) {
        int nos=0;
        int i=0;
        if(n<0)return false;
        while(n>>i){
            if((n>>i)&1)nos++;
            i++;
        }
        if(nos==1)return true;
        return false;
    }
};