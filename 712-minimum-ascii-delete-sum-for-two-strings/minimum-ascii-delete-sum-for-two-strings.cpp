class Solution {
public:
    vector<vector<int>> dp;
    int ans(int i1, int i2, string& s1, string& s2){
        if(i1>=s1.size() && i2>=s2.size())return 0;
        if(i1==s1.size()){
            int val=0;
            while(i2<s2.size()){
                val+=(int)s2[i2++];
            }
            return val;
        }
        if(i2==s2.size()){
            int val=0;
            while(i1<s1.size()){
                val+=(int)s1[i1++];
            }
            return val;
        }

        if(dp[i1][i2]!=-1)return dp[i1][i2];
        
        if(s1[i1]==s2[i2]){
            int skip=ans(i1+1,i2+1,s1,s2);
            int del1=(int)s1[i1]+ans(i1+1,i2,s1,s2);
            int del2=(int)s2[i2]+ans(i1,i2+1,s1,s2);

            return dp[i1][i2]=min(skip,min(del1,del2));
        }
        else{
            int del1=(int)s1[i1]+ans(i1+1,i2,s1,s2);
            int del2=(int)s2[i2]+ans(i1,i2+1,s1,s2);
            return dp[i1][i2]=min(del1,del2);
        }
        return 0;
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return ans(0,0,s1,s2);
    }
};