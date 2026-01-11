class Solution {
public:
    string minWindow(string s, string t) {
        map<char,pair<int,int>> mp; // char-> req, cur
        for(int i=0;i<t.size();i++){
            mp[t[i]].first++;
        }
        int l=0,r=0,prev=-1;
        int cnt=0;
        int ml=0,mr=INT_MAX-1;
        while(r<s.size() && l<=r){
            if(r!=prev){
                mp[s[r]].second++;
                if(mp[s[r]].first>=mp[s[r]].second)cnt++;
                prev=r;
            }
            if(cnt!=t.size())r++;
            else{
                int size=r-l+1;
                int msize=mr-ml+1;
                if(msize>size){
                    mr=r;
                    ml=l;
                }
                mp[s[l]].second--;
                if(mp[s[l]].first>mp[s[l]].second)cnt--;
                l++;
            }
        }

        string ans="";
        if(mr==INT_MAX-1)return ans;
        for(int i=ml;i<=mr;i++){
            ans.push_back(s[i]);
        }
        return ans;
    }
};