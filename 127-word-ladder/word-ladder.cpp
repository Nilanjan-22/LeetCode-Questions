class Solution {
public:
    int bfs(queue<pair<string,int>>& q, string& end, set<string>& st){
        int ans=1;
        while(!q.empty()){
            string word=q.front().first;
            int s=q.front().second;
            ans=max(ans,s);
            if(word==end)return ans;
            q.pop();
            for(int i=0;i<word.size();i++){
                string copy=word;
                for(char j='a';j<='z';j++){
                    copy[i]=j;
                    if(st.find(copy)!=st.end()){
                        q.push({copy,s+1});
                        st.erase(copy);
                    }
                }
            }
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        set<string> st;
        st.insert(beginWord);
        for(int i=0;i<n;i++){
            st.insert(wordList[i]);
        }
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);
        return bfs(q,endWord,st);
    }
};