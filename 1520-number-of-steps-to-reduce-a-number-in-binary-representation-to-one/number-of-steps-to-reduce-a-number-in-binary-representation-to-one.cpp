class Solution {
public:
    int numSteps(string s) {
        int ans=0;
        int n=s.size();

        for(int i=n-1;i>0;i--){
            if(s[i]=='0')ans++;
            else{
                int j=i;
                ans++;
                while(j>=0 && s[j]=='1'){
                    ans++;
                    j--;
                }
                if(j>=0)s[j]='1';
                i=j+1;
            }
        }
        return ans;
    }
};