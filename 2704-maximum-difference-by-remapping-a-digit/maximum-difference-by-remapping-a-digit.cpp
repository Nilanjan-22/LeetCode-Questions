class Solution {
public:
    int minMaxDifference(int num) {
        int cp=num;
        vector<int> digits;
        while(cp>0){
            digits.push_back(cp%10);
            cp/=10;
        }
        reverse(digits.begin(),digits.end());
        vector<int> dig=digits;
        int chng=-1;
        int n=digits.size();
        for(int i=0;i<n;i++){
            if(dig[i]>0 && chng==-1)chng=dig[i];
            if(dig[i]==chng)dig[i]=0;
        }
        chng=-1;
        for(int i=0;i<n;i++){
            if(digits[i]<9 && chng==-1)chng=digits[i];
            if(digits[i]==chng)digits[i]=9;
        }

        int mul=1;
        int num1=0,num2=0;
        for(int i=n-1;i>=0;i--){
            num1+=dig[i]*mul;
            num2+=digits[i]*mul;
            mul*=10;
        }
        return abs(num1-num2);
    }
};