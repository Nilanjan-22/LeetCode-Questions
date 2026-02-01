class Solution {
public:
    int countMonobit(int n) {
        int p=0,num=n+1;
        while(num){
            num/=2;
            p++;
        }
        return p;
    }
};