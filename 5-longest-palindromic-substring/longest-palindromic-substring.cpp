class Solution {
public:
    string longestPalindrome(string s) {
        string longestPal="";
        int n=s.size();
        for(int i=0;i<s.size();i++){
            //taking it as center
            int i1=i-1,i2=i+1;
            while(i1>=0 && i2<n && s[i1]==s[i2]){
                i1--;
                i2++;
            }

            int j1=i,j2=i+1;
            while(j1>=0 && j2<n && s[j1]==s[j2]){
                j1--;
                j2++;
            }
            int st,en;
            if(j2-j1 > i2-i1){
                st=j1+1;
                en=j2;
            }
            else{
                st=i1+1;
                en=i2;
            }
            if(longestPal.size()<en-st){
                longestPal= s.substr(st,en-st);
            }
        }
        return longestPal;
    }
};