class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string finalWord="";
        for(auto word: words){
            int result=0;
            for(auto letter : word){
                result+=weights[letter-'a'];
            }
            result%=26;
            result=25-result;
            finalWord.push_back('a'+result);
        }
        return finalWord;
    }
};