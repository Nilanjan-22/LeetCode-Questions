class Solution {
public:
    bool checkOnesSegment(string s) {
        int f=false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                if(f)return false;
                f=true;
                while(i<s.size() && s[i]=='1')i++;
                i--;
            }
        }
        return true;
    }
};