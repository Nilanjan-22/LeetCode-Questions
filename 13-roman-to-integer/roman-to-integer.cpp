class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;
        mp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

        int intValue=0;
        for(int i=0;i<s.size();i++){
            if(i==s.size()-1 || mp[s[i]]>=mp[s[i+1]])intValue+=mp[s[i]];
            else intValue-=mp[s[i]];
        }
        return intValue;
    }
};