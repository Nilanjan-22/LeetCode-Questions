class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> ans;
        string word;
        while(ss>>word){
            ans.push_back(word);
        }
        
        word="";
        int n=ans.size();
        for(int i=n-1;i>=0;i--){
            word+=ans[i];
            word+=" ";
        } 
        word.pop_back();
        return word;
    }
};