class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n=folder.size();
        vector<pair<int,string>> v;
        for(int i=0;i<n;i++){
            int depth=0;
            for(auto it:folder[i]){
                if(it=='/')depth++;
            }
            v.push_back({depth,folder[i]});
        }
        sort(v.begin(),v.end());
        vector<string>ans;
        set<string> st;
        for(int i=0;i<n;i++){
            string s=v[i].second;
            if(st.empty()){
                st.insert(s);
                ans.push_back(s);
            }
            else{
                bool found=false;
                string chk="";
                for(auto it:s){
                    if(it=='/' && st.find(chk)!=st.end()){
                        found=true;
                        break;
                    }
                    chk.push_back(it);
                }
                if(!found){
                    st.insert(s);
                    ans.push_back(s);
                }
            }

        }
        return ans;
    }
};