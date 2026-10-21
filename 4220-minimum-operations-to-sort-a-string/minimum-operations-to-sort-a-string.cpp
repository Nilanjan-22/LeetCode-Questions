class Solution {
public:
    int minOperations(string s) {
        char largest='a',smallest='z';
        map<char,int> uniques;
        for(auto ch: s){
            if(largest<ch)largest=ch;
            if(smallest>ch)smallest=ch;
            uniques[ch]++;
        }
        
        string sorted=s;
        sort(sorted.begin(),sorted.end());
        if(sorted==s)return 0;
        else if(s.size()==2)return -1;
        else if(s[0]==smallest || s[s.size()-1]==largest)return 1;
        else if(s[0]==largest && s[s.size()-1]==smallest && uniques.size()>2 && uniques[smallest]==1 && uniques[largest]==1)return 3;
        else return 2;
    }
};