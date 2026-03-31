class Solution {
public:
    string generateString(string str1, string str2) {
        int n=str2.size();
        int s=str1.size()+n-1;
        string ans(s,'a');
        vector<int> canChange(s,1);
        for(int i=0;i<str1.size();i++){
            if(str1[i]=='T'){
                for(int j=i;j<i+n;j++){
                    if(ans[j]!=str2[j-i] && canChange[j]==0)return "";
                    ans[j]=str2[j-i];
                    canChange[j]=0;
                }
            }
        }

        for(int i=0;i<str1.size();i++){
            if(str1[i]=='F'){
                if(ans.substr(i,n)==str2){
                    bool done=false;
                    for(int j=i+n-1;j>=i;j--){
                        if(canChange[j]==1 && ans[j]!='z'){
                            ans[j]=ans[j]+1;
                            done=true;
                            break;
                        }
                    }
                    if(!done)return "";
                }
            }
        }

        return ans;
    }
};