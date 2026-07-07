class Solution {
public:
    long long sumAndMultiply(int n) {
        long long newNum=0;
        long long sumOfDig=0;

        long long temp=n;
        long long place=-1;
        while(temp>0){
            long long dig=temp%10;
            temp/=10;
            if(dig==0)continue;
            place++;
            sumOfDig+=dig;
            dig*=pow(10LL,place);
            newNum+=dig;
        }

        return newNum*sumOfDig;
    }
};