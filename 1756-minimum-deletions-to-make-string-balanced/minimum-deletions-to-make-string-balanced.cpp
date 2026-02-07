class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int> cnta(n+1),cntb(n+1);
        cnta[n]=0;
        cntb[0]=0;
        int cnt1=0,cnt2=0,j=n-1;
        for(int i=0;i<n;i++){
            if(s[i]=='b')cnt1++;
            if(s[j]=='a')cnt2++;
            cntb[i+1]=cnt1;
            cnta[j]=cnt2;
            j--;
        }

        int ans=n;
        for(int i=-1;i<n;i++){
            ans=min(ans,cnta[i+1]+cntb[i+1]);
        }
        // if(n==1)return 0;
        return ans;
    }
};