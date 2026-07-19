class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_set<char> charSet;
        unordered_map<char,int> lastIdx;
        for(int i=0;i<s.size();i++){
            lastIdx[s[i]]=i;
        }

        string ans;

        for(int i=0;i<s.size();i++){
            if(charSet.find(s[i])!=charSet.end())continue;

            while(ans.size()>0 && ans.back()>s[i] && lastIdx[ans.back()]>i){
                charSet.erase(ans.back());
                ans.pop_back();
                
            }
            ans.push_back(s[i]);
            charSet.insert(s[i]);
        }

        return ans;
    }
};