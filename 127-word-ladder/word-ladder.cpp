class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& wl) {
        //here bw is my src node
        // we will simply apply bfs in every direction
        // but before that instead of a visited vector we will use a set
        //the set will store the strings

        set<string> st;
        st.insert(bw);
        int n=wl.size();
        for(int i=0;i<n;i++){
            st.insert(wl[i]);
        }

        //now we will declare the queue which will store pairs
        //one of which is the string and the other is the number of paths taken to reach that string

        queue<pair<string,int>> q;
        //we will push the src string
        q.push({bw,1});
        st.erase(bw);
        while(!q.empty()){
            string s=q.front().first;
            int d=q.front().second;
            q.pop();
            //we have to go to every possibility and check if it exists in the set
            //if it does push it in the queue
            for(int i=0;i<s.size();i++){
                string copy=s;
                for(char it ='a';it<='z';it++){
                    copy[i]=it;
                    if(st.count(copy)>0){
                        if(copy==ew)return d+1;
                        q.push({copy,d+1});
                        st.erase(copy);
                    }
                }
            }

        }
        return 0;
    }
};