class Solution {
public:
    int m=1e9+7;
    vector<int> bin;
    void add(long long& ans, int n){
        bin.clear();
        while(n>0){
            int rem=n%2;
            n/=2;
            bin.push_back(rem);
        }
        for(int i=bin.size()-1;i>=0;i--){
            ans%=m;
            ans*=2;
            ans+=bin[i];
            ans%=m;
        }
    }
    int concatenatedBinary(int n) {
        long long ans=0;
        for(int i=1;i<=n;i++){
            add(ans,i);
        }
        return ans%m;
    }
};