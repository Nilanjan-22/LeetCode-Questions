class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        vector<vector<int>> hash(n+1,vector<int>(26,0));
        for(int i=0;i<n;i++){
            hash[i+1]=hash[i];
            hash[i+1][s[i]-'a']++;
        }
        // for(auto it: hash){
        //     for(auto cnt : it){
        //         cout<<cnt<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<int> ans;
        vector<int> reqHash(26,0);
        for(auto it: p){
            reqHash[it-'a']++;
        }

        int st=0,en=p.size();
        while(en<=n){
            bool ana=true;
            for(int i=0;i<26;i++){
                if(reqHash[i] != hash[en][i]-hash[st][i]){
                    ana=false;
                    break;
                }
            }
            if(ana)ans.push_back(st);
            st++;
            en++;
        }

        return ans;
    }
};