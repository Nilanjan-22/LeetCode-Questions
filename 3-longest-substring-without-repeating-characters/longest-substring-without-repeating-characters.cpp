class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> foundCharacters;
        int st=-1, longestSubstring=0;
        for(int i=0;i<s.size();i++){
            if(foundCharacters.find(s[i])!=foundCharacters.end()){
                // longestSubstring=max(longestSubstring, i-foundCharacters[s[i]]);
                if(foundCharacters[s[i]]>=st){
                    st=foundCharacters[s[i]];
                }
            }
            foundCharacters[s[i]]=i;
            longestSubstring=max(longestSubstring, i-st);
        }
        return longestSubstring;
    }
};