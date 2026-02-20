class Solution {
public:
    string makeLargestSpecial(string s) {
        int st=0;
        int cnt=0;
        vector<string> res;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')cnt++;
            else cnt--;

            if(cnt==0){
                res.push_back('1' + makeLargestSpecial(s.substr(st+1,i-st-1)) +'0');

                st=i+1;
            }
        }

        sort(res.rbegin(),res.rend());

        string ans;
        for(auto str:res){
            ans+=str;
        }
        return ans;
    }
};