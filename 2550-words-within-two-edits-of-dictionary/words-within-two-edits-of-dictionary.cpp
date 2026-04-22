class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> matchingWords;
        int mismatch;
        for(int i=0;i<queries.size();i++){
            for(int j=0;j<dictionary.size();j++){
                mismatch=0;
                for(int k=0;k<queries[i].size();k++){
                    if(queries[i][k]!=dictionary[j][k])mismatch++;
                    if(mismatch>2)break;
                }
                if(mismatch<=2){
                    matchingWords.push_back(queries[i]);
                    break;
                }
            }
        }
        return matchingWords;
    }
};