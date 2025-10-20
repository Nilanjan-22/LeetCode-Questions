class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        int n=words.size();
        int i=0,j=1;
        string chk=words[i];
        sort(chk.begin(),chk.end());
        while(i<n && j<n){
            string com=words[j];
            sort(com.begin(),com.end());
            if(com==chk)j++;
            else{
                ans.push_back(words[i]);
                i=j;
                chk=words[i];
                sort(chk.begin(),chk.end());
                j++;
            }
        }
        ans.push_back(words[i]);
        return ans;
    }
};