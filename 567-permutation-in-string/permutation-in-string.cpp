class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> reqHash(26,0);
        int n=s2.size();
        for(auto it: s1){
            reqHash[it-'a']++;
        }
        vector<vector<int>> hash(n+1,vector<int>(26,0));

        for(int i=1;i<=n;i++){
            hash[i]=hash[i-1];
            hash[i][s2[i-1]-'a']++;
        }

        int en=s1.size(),st=0;

        while(en<=n){
            bool notMatch=false;
            for(int i=0;i<26;i++){
                if(reqHash[i] != hash[en][i]-hash[st][i]){
                    notMatch=true;
                    break;
                }
            }
            if(!notMatch)return true;
            en++;
            st++;
        }
        return false;
    }
};