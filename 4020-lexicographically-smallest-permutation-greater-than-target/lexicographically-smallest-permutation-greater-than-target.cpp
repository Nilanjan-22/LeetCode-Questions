class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        sort(s.rbegin(),s.rend());
        if(s<=target)return "";
        
        map<char,int> mp;
        for(auto it:s){
            mp[it]++;
        }
        string ans="";
        bool high=false;
        for(int i=0;i<s.size();i++){
            auto it = mp.lower_bound(target[i]);
            if(it==mp.end()){
                for(auto itr = mp.rbegin() ; itr!=mp.rend(); itr++){
                    int rep = itr->second;
                    while(rep>0){
                        ans.push_back(itr->first);
                        rep--;
                    }
                }
                break;
            }
            char ch = it->first;
            int val = it->second;
            ans.push_back(ch);
            if(val==1)mp.erase(ch);
            else mp[ch]=val-1;
            if(ch>target[i]){
                high=true;
                break;
            }
        }
        if(high){
            for(auto it: mp){
                int rep = it.second;
                while(rep>0){
                    ans.push_back(it.first);
                    rep--;
                }
            }
        }
        else{
            s=ans;
            ans="";
            int mismatch;
            string soFar="";
            for(int i=s.size()-1;i>=1;i--){
                soFar.push_back(s[i]);
                if(s[i-1]<s[i]){
                    mismatch=i-1;
                    break;
                }
            }
            sort(soFar.begin(),soFar.end());
            for(int i=0;i<mismatch;i++){
                ans.push_back(target[i]);
            }
            int ind = upper_bound(soFar.begin(),soFar.end(),s[mismatch])-soFar.begin();
            ans.push_back(soFar[ind]);
            soFar[ind]=s[mismatch];
            ans+=soFar;

        }
        return ans;
    }
};