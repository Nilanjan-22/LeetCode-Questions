class Solution {
public:
    int smallestNumber(int n, int t) {
        int num=n;
        while(true){
            int prod=1;
            int temp=num;
            while(temp){
                prod*=temp%10;
                temp/=10;
            }
            if(prod%t==0)return num;
            num++;
        }
    }
};