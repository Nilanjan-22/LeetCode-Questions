class Solution {
public:
    
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<int> matchingSuff(n+1,m-1);
        int it=m-1;
        for(int i=n-1;i>=0;i--){
            if(it>=0 && word1[i]==word2[it]){
                matchingSuff[i] = it;
                it--;
            }
            else{
                if(i<n-1) matchingSuff[i]=matchingSuff[i+1];
            }
        }
        // for(auto it: matchingSuff)cout<<it<<" ";
        vector<int> validSeq;
        it=0;
        bool changed=false;
        for(int i=0;i<n;i++){
            if(it==m)break;
            if(word1[i]==word2[it]){
                validSeq.push_back(i);
                it++;
            }
            else if(matchingSuff[i]<=it+1 && matchingSuff[i]==matchingSuff[i+1]){
                if(!changed){
                    changed=true;
                    validSeq.push_back(i);
                    it++;
                }
            }
        }
        // return validSeq;
        if(validSeq.size()==m)return validSeq;
        return {};
    }
};