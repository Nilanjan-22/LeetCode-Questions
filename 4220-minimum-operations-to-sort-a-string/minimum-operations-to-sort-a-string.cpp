class Solution {
public:
    int minOperations(string s) {
        int n=s.size();

        if(s.size()==2 && s[0]>s[1])return -1;
        string c=s;
        sort(c.begin(),c.end());
        if(c==s)return 0;

        int small=0,big=0;
        map<char,int> mp;
        for(int i=0;i<s.size();i++){
            if(s[i]<s[small])small=i;
            if(s[i]>=s[big])big=i;
            mp[s[i]]++;
        }
        if(s[small]==s[0] || s[big]==s[n-1])return 1;
        else if(s[big]==s[0] && s[small]==s[n-1] && mp[s[big]]==1 && mp[s[small]]==1)return 3;
        else return 2;
        
    }
};