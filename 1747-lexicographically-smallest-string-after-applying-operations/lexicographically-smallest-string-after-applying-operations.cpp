class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        map<string,bool> visited;
        string copy=s;
        visited[copy]=true;

        queue<string> q;
        q.push(copy);
        
        string ans=copy;
        while(!q.empty()){
            string top=q.front();
            q.pop();

            //add
            for(int i=1;i<top.size();i+=2){
                top[i]=(int)(top[i]-'0'+a)%10+'0';
            }
            ans=min(ans,top);
            if(visited.find(top)==visited.end()){
                visited[top]=true;
                q.push(top);
            }

            //rotate
            rotate(top.begin(), top.begin()+top.size()-b,top.end());
            ans=min(ans,top);
            if(visited.find(top)==visited.end()){
                visited[top]=true;
                q.push(top);
            }
        }

        return ans;
    }
};