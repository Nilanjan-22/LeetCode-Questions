class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int it=0;
        for(int i=0;i<s.size();i++){
            if(it<g.size() && s[i]>=g[it]){
                it++;
            }
        }

        return it;
    }
};