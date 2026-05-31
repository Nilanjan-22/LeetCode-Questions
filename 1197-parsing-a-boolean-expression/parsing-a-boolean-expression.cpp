class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<vector<int>> st; //{ex,nof,not} //0->!,1->|,2->&
        map<char,int> exp;
        exp['!']=0;
        exp['|']=1;
        exp['&']=2;

        int nof=0,Not=0;
        for(int i=0;i<expression.size();i++){
            if(expression[i]=='('){
                st.push({exp[expression[i-1]],nof,Not});
                nof=0;
                Not=0;
            }
            else if(expression[i]=='t')Not++;
            else if(expression[i]=='f')nof++;
            else if(expression[i]==')'){
                int curf=nof, curt=Not;
                nof=st.top()[1];
                Not=st.top()[2];
                int ex=st.top()[0];
                st.pop();
                if(ex==0){
                    if(curf==0)nof++;
                    else Not++;
                }
                else if(ex==1){
                    if(curt==0)nof++;
                    else Not++;
                }
                else{
                    if(curf==0)Not++;
                    else nof++;
                }
            }
        }

        if(nof==0)return true;
        else return false;
    }
};