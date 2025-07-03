class Solution {
public:
    char kthCharacter(int k) {
        int l=0;
        while(k>>l)l++;

        string s="a";
        int ini=1;

        for(int i=0;i<l;i++){
            s+=s;
            for(int i=ini;i<s.size();i++){
                s[i]++;
            }
            ini=s.size();
        }
        cout<<s<<endl;
        return s[k-1];
    }
};