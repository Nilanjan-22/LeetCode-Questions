class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<pair<int,int>> continuosSessions;
        int len=0;
        int maxSessions=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                if(len<0){
                    continuosSessions.push_back({-len,0});
                    len=0;
                }
                len++;
            }
            else {
                if(len>0){
                    continuosSessions.push_back({len,1});
                    maxSessions+=len;
                    len=0;
                }
                len--;
            }
        }
        if(len<0)continuosSessions.push_back({-len,0});
        if(len>0){
            continuosSessions.push_back({len,1});
            maxSessions+=len;
        }

        int n=continuosSessions.size();
        int i=0;
        int maxInc=0;
        int cur=0;
        while(i<n-2){
            if(continuosSessions[i].second==0){
                int j=i;
                cur=0;
                while(j-i<=2){
                    cur+=continuosSessions[j].first;
                    j+=2;
                }
                maxInc=max(cur,maxInc);
            }
            i++;
        }
        return maxSessions+maxInc;
    }
};