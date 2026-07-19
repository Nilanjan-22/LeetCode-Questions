class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        for(int i=0;i<s.size();i++){
            if(s[i]==y)s[i]='0';
        }

        sort(s.begin(),s.end());
        int i=0;
        while(s[i]=='0'){
            s[i]=y;
            i++;
        }
        return s;

    }
};