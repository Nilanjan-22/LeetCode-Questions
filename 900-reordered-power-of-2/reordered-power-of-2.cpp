class Solution {
public:
    void store(int n, set<string>& st){
        string s="";
        while(n>0){
            s.push_back(n%10);
            n/=10;
        }
        sort(s.begin(),s.end());
        st.insert(s);
    }
    bool reorderedPowerOf2(int n) {
        set<string> st;
        // store all the powers of 2 in a string and before storing sort it
        for(int i=0;i<31;i++){
            store(1<<i,st);
        }
        string s="";
        while(n>0){
            s.push_back(n%10);
            n/=10;
        }
        sort(s.begin(),s.end());

        if(st.find(s)!=st.end())return true;
        return false;
        

    }
};