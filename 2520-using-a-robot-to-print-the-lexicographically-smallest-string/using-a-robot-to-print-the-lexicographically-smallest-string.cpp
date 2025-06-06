class Solution {
public:
    string robotWithString(string s) {
        int n=s.size();
        vector<int> mp(26,0);
        string p="",t="";
        for(int i=0;i<n;i++){
            mp[s[i]-97]++;
        }

        for(int i=0;i<n;){
            char ch=s[i];
            for(char it=0;it<s[i]-97;it++){
                if(mp[it]>0){
                    ch=(char)(it+97);
                    break;
                }
            }
            int j=t.size()-1;
            while(j>=0 && t[j]<=ch){
                p.push_back(t[j]);
                t.pop_back();
                j--;
            }
            while(mp[ch-97]>0 && i<n){
                if(s[i]!=ch)t.push_back(s[i]);
                else p.push_back(s[i]);
                mp[s[i]-97]--;
                i++;
            }
        }

        reverse(t.begin(),t.end());
        p=p+t;
        return p;
    }
};