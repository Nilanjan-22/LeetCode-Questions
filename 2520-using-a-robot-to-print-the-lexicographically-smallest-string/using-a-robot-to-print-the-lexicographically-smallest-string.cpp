class Solution {
public:
    string robotWithString(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        string p="",t="";
        for(int i=0;i<n;i++){
            if(mp.find(s[i])==mp.end())mp[s[i]]=1;
            else mp[s[i]]++;
        }

        for(int i=0;i<n;){
            char ch=s[i];
            for(char it='a';it<s[i];it++){
                if(mp[it]>0){
                    ch=it;
                    break;
                }
            }
            int j=t.size()-1;
            while(j>=0 && t[j]<=ch){
                p.push_back(t[j]);
                t.pop_back();
                j--;
            }
            while(mp[ch]>0 && i<n){
                if(s[i]!=ch)t.push_back(s[i]);
                else p.push_back(s[i]);
                mp[s[i]]--;
                i++;
            }
        }

        reverse(t.begin(),t.end());
        p=p+t;
        return p;
    }
};