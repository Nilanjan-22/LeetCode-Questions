class Solution {
public:
    string maximumXor(string s, string t) {
        string ans=s;
        int s0=0,s1=0,t1=0,t0=0;
        int n=t.size();
        for(int i=0;i<n;i++){
            if(s[i]=='1')s1++;
            else s0++;

            if(t[i]=='1')t1++;
            else t0--;
        }

        if(s0>=t1){
            for(int i=0;i<n;i++){
                if(t1==0)break;
                if(ans[i]=='0'){
                    ans[i]='1';
                    t1--;
                }
            }
        }
        else{
            int zer=t1-s0;
            for(int i=n-1;i>=0;i--){
                if(ans[i]=='0')ans[i]='1';
                else{
                    if(zer>0){
                        ans[i]='0';
                        zer--;
                    }
                }
            }
        }
        return ans;
    }
};