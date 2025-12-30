class Solution {
public:
    int longestValidParentheses(string s) {
        int left=0;
        stack<pair<int,int>> check;
        int ans=0, valid=0;

        for(int i=0;i<s.size();i++){
            if(left==0 && s[i]==')'){
                ans=max(ans,valid);
                valid=0;
                check={};
            }
            else{
                if(left>0 && s[i]==')'){
                    valid++;
                    left--;
                    while(check.top().first>left)check.pop();
                    if(check.top().first==left){
                        valid=i-check.top().second+1;
                    }
                    ans=max(ans,valid);
                }
                else if(s[i]=='('){
                    if(check.empty() || check.top().first!=left)check.push({left,i});

                    left++;
                    valid=1;
                }
            }

        }
        return ans;
    }
};