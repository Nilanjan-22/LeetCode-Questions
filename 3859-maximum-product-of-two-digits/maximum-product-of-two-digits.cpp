class Solution {
public:
    int maxProduct(int n) {
        int num1=-1, num2=-1;
        while(n>0){
            int dig = n%10;
            if(num1<dig){
                num2=num1;
                num1=dig;
            }
            else if(num2<dig){
                num2=dig;
            }
            n/=10;
        }
        return num1*num2;
    }
};