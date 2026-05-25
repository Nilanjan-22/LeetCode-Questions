class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> q;
        q.push(0);
        int scanned=0;
        while(!q.empty()){
            int pos=q.front();
            q.pop();

            if(pos==s.size()-1)return true;
            
            for(int i=max(pos+minJump, scanned+1); i<=min(pos+maxJump,(int)s.size()-1); i++){
                if(s[i]=='0'){
                    q.push(i);
                }
            }
            scanned=max(scanned,pos+maxJump);
        }
        return false;
    }
};