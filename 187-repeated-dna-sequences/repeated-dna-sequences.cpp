class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> repeatedSeq;
        unordered_map<string,int> hashMap;
        int en=0;
        string it="";
        while(en<10){
            it.push_back(s[en]);
            en++;
        }
        hashMap[it]=1;
        while(en<s.size()){
            it.erase(0,1);
            it.push_back(s[en]);
            hashMap[it]++;
            if(hashMap[it]==2)repeatedSeq.push_back(it);
            en++;
        }
        return repeatedSeq;
    }
};