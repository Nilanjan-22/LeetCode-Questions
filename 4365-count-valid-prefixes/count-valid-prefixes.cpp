class Solution {
public:
    int countValidPrefixes(string s) {
        int validPref=0;
        int cnt1=0,cnt0=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0')cnt0++;
            else cnt1++;

            if(abs(cnt1-cnt0)<2)validPref++;
        }
        return validPref;
    }
};