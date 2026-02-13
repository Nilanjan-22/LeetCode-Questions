class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int ans=1;
        int len=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1])len++;
            else len=1;
            ans=max(ans,len);
        }
        map<pair<int,int>,int> abc,ab,bc,ca;
        abc[{0,0}]=-1;
        ab[{0,0}]=-1;
        bc[{0,0}]=-1;
        ca[{0,0}]=-1;

        vector<int> cnt(3,0);
        for(int i=0;i<n;i++){
            cnt[s[i]-'a']++;

            int a=cnt[0],b=cnt[1],c=cnt[2];
            //balance a b c
            // cout<<a<<" "<<b<<" "<<c<<" -> "<<i<<endl;
            if(abc.find({b-a,c-a})!=abc.end())ans=max(ans,i-abc[{b-a,c-a}]);
            else{
                abc[{b-a,c-a}]=i;
            }

            //balance a b
            if(ab.find({a-b,c})!=ab.end())ans=max(ans,i-ab[{a-b,c}]);
            else {
                ab[{a-b,c}]=i;
            }

            //balance b c
            if(bc.find({b-c,a})!=bc.end())ans=max(ans,i-bc[{b-c,a}]);
            else{
                bc[{b-c,a}]=i;
            }

            //balance a c
            if(ca.find({c-a,b})!=ca.end())ans=max(ans,i-ca[{c-a,b}]);
            else{
                ca[{c-a,b}]=i;
            }
        }
        return ans;
    }
};