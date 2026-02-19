class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> conse;
        int prev=s[0],cnt=0,last;
        for(int i=0;i<s.size();i++){
            if(prev==s[i])cnt++;
            else{
                conse.push_back(cnt);
                prev=s[i];
                cnt=1;
                last=i;
            }
        }
        conse.push_back(cnt);

        int ans=0;
        for(int i=0;i<conse.size()-1;i++){
            int mini=min(conse[i],conse[i+1]);
            ans+=mini;
        }

        return ans;
    }
};