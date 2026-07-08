class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size(), m=queries.size();
        int mod=1e9+7;
        vector<long long> sumPref(n+1,0);
        vector<pair<long long,int>> num(n+1,{0,0});
        for(int i=0;i<n;i++){
            sumPref[i+1]=sumPref[i]+(s[i]-'0');
        }

        for(int i=0;i<n;i++){
            int cnt=num[i].second;
            long long number=num[i].first;
            if(s[i]!='0'){
                cnt++;
                number%=mod;
                number*=10;
                number+=s[i]-'0';
                number%=mod;
            }
            num[i+1]={number,cnt};
        }
        vector<int> powerOfTen(1e5+1,1);
        long long p=1;
        for(int j=1;j<1e5+1;j++){
            p*=10LL;
            p%=mod;
            powerOfTen[j]=p;
        }
        vector<int> ans;

        for(int i=0;i<m;i++){
            int l=queries[i][0], r=queries[i][1];
            int cntDiff=num[r+1].second-num[l].second;
            long long number = num[r+1].first;
            long long sub=num[l].first ;
            long long pow=powerOfTen[cntDiff];
            sub*=pow;
            sub%=mod;
            number-=sub;
            if(number<0)number+=mod;
            else number%=mod;
            long long sum=sumPref[r+1]-sumPref[l];

            long long val = (number*sum)%mod;
            ans.push_back(val);
        }

        return ans;


    }
};