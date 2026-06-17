class Solution {
public:
    char processStr(string s, long long k) {
        long long finalLen=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='*' &&  finalLen>0)finalLen--;
            else if(s[i]=='#')finalLen*=2LL;
            else if(s[i]>='a' && s[i]<='z')finalLen++;
        }

        if(finalLen<=k)return '.';
        for(int i=n-1;i>=0;i--){
            if(s[i]=='#'){
                finalLen/=2;
                if(finalLen<=k)k-=finalLen;
            }
            else if(s[i]=='%'){
                k=finalLen-k-1;
            }
            else if(s[i]=='*' && finalLen>0)finalLen++;

            else {
                if(finalLen==k+1)return s[i];
                finalLen--;
            }
        }
        return '.';
    }
};