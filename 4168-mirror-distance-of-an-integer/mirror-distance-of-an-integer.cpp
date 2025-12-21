class Solution {
public:
    int mirrorDistance(int n) {
        int c=n ,rev=0;
        int mul = 0;
        while(c/10>0){
            c/=10;
            mul++;
        }
        c=n;
        while(c>0){
            rev+=(c%10)*pow(10,mul);
            mul--;
            c/=10;
        }

        return abs(rev-n);

    }
};