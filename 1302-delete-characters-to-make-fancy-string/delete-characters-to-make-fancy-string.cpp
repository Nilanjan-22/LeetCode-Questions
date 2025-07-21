class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        int cnt=0;
        char prev='1';
        for(int i=0;i<s.size();i++){
            if(prev==s[i] && cnt==2)continue;
            else if(prev==s[i]){
                cnt++;
                ans.push_back(s[i]);
            }
            else {
                cnt=1;
                prev=s[i];
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};