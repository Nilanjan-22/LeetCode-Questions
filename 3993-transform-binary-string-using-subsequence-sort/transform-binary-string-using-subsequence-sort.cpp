class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n=s.size();
        vector<int> countOnes(n,0);
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                if(i==0)countOnes[i]=1;
                else countOnes[i]=countOnes[i-1]+1;
            }
            else if(i>0)countOnes[i]=countOnes[i-1];
        }

        vector<bool> ans(strs.size(),true);
        for(int i=0;i<strs.size();i++){
            string sub = strs[i];
            int cnt1=0,cnt0=0;
            for(int ind=0;ind<n;ind++){
                if(sub[ind]=='1')cnt1++;
                else if(sub[ind]=='0')cnt0++;
            }
            int req1=countOnes[n-1]-cnt1;
            int req0=n-countOnes[n-1]-cnt0;

            if(req1<0 || req0<0){
                ans[i]=false;
                continue;
            }
            cnt1=0;
            for(int ind=0;ind<n;ind++){
                if(sub[ind]=='1' || (sub[ind]=='?' && req0==0)){
                    cnt1++;
                    if(countOnes[ind]<cnt1){
                        ans[i]=false;
                        break;
                    }
                }
                else if(sub[ind]=='?')req0--;
            }
        }
        return ans;
    }
};