class Solution {
public:
    int vectonum(vector<int>&v){
        int n=v.size();
        int num=0;
        for(int i=0;i<n;i++){
            num+=v[i]*pow(10,i);
        }
        return num;
    }
    int nextBeautifulNumber(int n) {
        //n is less than equals 1e6
        //hence there are very limited options
        //combination of 1+5,5,2+3,1+4,4,1+3,1+2,3,2,1
        //total 28 combinations
        vector<vector<int>> vec={{1,2,2,3,3,3},{1,5,5,5,5,5},{2,2,4,4,4,4},{2,2,3,3,3},{1,4,4,4,4},{1,3,3,3},{1,2,2}};
        set<int> st;
        st.insert(1224444);
        for(int i=6;i>0;i--){
            int num=0;
            int j=0;
            while(j<i){
                num+=i*pow(10,j);
                j++;
            }
            st.insert(num);
        }
        for(int i=0;i<vec.size();i++){
            do{
                int num=vectonum(vec[i]);
                st.insert(num);}
            while(next_permutation(vec[i].begin(),vec[i].end()));
            
        }
        for(auto it: st)cout<<it<<" ";
        return *st.upper_bound(n);
    }
};