class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n=word.size();
        unordered_map<string,int> patternsFreq;
        for(auto s: patterns){
            patternsFreq[s]++;
        }

        for(int i=0;i<n;i++){
            string str="";
            for(int j=i;j<n;j++){
                str+=word[j];
                if(patternsFreq.find(str)!=patternsFreq.end()){
                    patternsFreq[str]=0;
                }
            }
        }

        int ans=patterns.size();
        for(auto it: patternsFreq){
            ans-=it.second;
        }
        return ans;

    }
};