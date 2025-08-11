class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> v;
        int i=0;
        while(n>>i){
            if(n>>i & 1)v.push_back(1<<i);
            i++;
        }
        int m=1e9+7;
        int s=v.size();

        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int r=queries[i][1], l=queries[i][0];
            long long mul=1;
            while(l<=r){
                mul*=v[l];
                mul%=m;
                l++;
            }
            ans.push_back(mul);
        }

        return ans;


    }
};