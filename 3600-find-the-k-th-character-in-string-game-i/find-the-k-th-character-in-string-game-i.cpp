class Solution {
public:
    char kthCharacter(int k) {
        
        int cnt=0;
        while(k>1){
            int l= __lg(k);
            if(pow(2,l)==k)l--;
            k-=pow(2,l);
            cnt++;
        }
        return (char)97+cnt;
    }
};