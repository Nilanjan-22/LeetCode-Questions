class Solution {
public:
    queue<pair<string,int>> q;
    set<string> st;
    int bfs(string endWord){
        int ans=0;
        while(!q.empty()){
            string s=q.front().first;
            int d=q.front().second;
            q.pop();
            ans=max(ans,d);
            if(s==endWord)return ans;

            for(int i=0;i<s.size();i++){
                string c=s;
                for(char j='a';j<='z';j++){
                    c[i]=j;
                    if(st.find(c)!=st.end()){
                        q.push({c,d+1});
                        st.erase(c);
                    }
                }
            }
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(int i=0;i<wordList.size();i++){
            st.insert(wordList[i]);
        }
        q.push({beginWord,1});
        return bfs(endWord);

    }
};