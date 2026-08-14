class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> hash;
        int en=0,st=0;
        int maxLen=0;
        while(en<s.size()){
            hash[s[en]]++;
            while(hash[s[en]]>2){
                hash[s[st]]--;
                st++;
            }
            maxLen = max(maxLen, en-st+1);
            en++;
        }
        return maxLen;
    }
};