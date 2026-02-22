class Solution {
public:
    bool isDigitorialPermutation(int n) {
        map<int,int> digits;
        int temp=n;
        int sum=0;
        while(temp){
            int num=temp%10;
            digits[temp%10]++;
            temp/=10;
            int mul=1;
            for(int i=1;i<=num;i++){
                mul*=i;
            }
            sum+=mul;
        }
        while(sum){
            digits[sum%10]--;
            sum/=10;
        }

        for(auto it: digits){
            if(it.second!=0)return false;
        }
        return true;

    }
};