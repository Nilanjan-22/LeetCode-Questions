class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<pair<int,int>> hash(26,{0,0});
        int specialChars=0;
        for(int i=0;i<word.size();i++){
            if(word[i]-'A' <26){
                int ind=word[i]-'A';
                if(hash[ind].second>0 && hash[ind].first==0){
                    specialChars++;
                    hash[ind].first=INT_MIN;
                }
                hash[ind].first++;
            }
            else{
                int ind=word[i]-'a';
                if(hash[ind].first<0 && hash[ind].second>0){
                    specialChars--;
                    hash[ind].second=INT_MIN;
                }
                hash[ind].second++;
            }
        }

        return specialChars;
    }
};