class Solution {
public:
    string smallestPalindrome(string s) {
        unordered_map<char,int> mp;
        int n=s.size();
        string ans(n,'-');
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        int st=0,en=n-1;
        for(char ch = 'a'; ch<='z';ch++){
            if(mp.find(ch)==mp.end())continue;

            if(mp[ch]%2==1){
                ans[n/2]=ch;
                mp[ch]--;
            }

            while(mp[ch]>0){
                ans[st]=ch;
                ans[en]=ch;
                st++;
                en--;
                mp[ch]-=2;
            }
        }
        return ans;
    }
};