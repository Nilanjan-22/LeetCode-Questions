class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        vector<int> rem(26,0) , cnt(26,0);
        string ans="";
        for(int i=0;i<s.size();i++){
            rem[s[i]-'a']++;
        }

        for(int i=0;i<s.size();i++){
            int num=s[i]-'a';
            while(ans.size()>0){
                int chk=ans.back()-'a';
                if(ans.back()>s[i] && (rem[chk]>0 || cnt[chk]>1)){
                    cnt[chk]--;
                    ans.pop_back();
                }
                else{
                    break;
                }
            }
            rem[num]--;
            cnt[num]++;
            ans.push_back(s[i]);

        }

        while(ans.size()>0 && cnt[ans.back()-'a']>1){
            cnt[ans.back()-'a']--;
            ans.pop_back();
        }
        return ans;
    }
};