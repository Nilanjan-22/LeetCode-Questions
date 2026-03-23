class Solution {
public:
    long long ans(int st, int en, int encCost, int flatCost, vector<int>&pref ){
        long long xcnt=pref[en]-pref[st];
        long long l=en-st;
        long long cost;
        if(xcnt==0){
            cost=flatCost;
        }
        else{
            cost=l*xcnt*(long long)encCost;
        }
        if(l%2==1)return cost;
        int mid=(st+en)/2;
        return min(cost, ans(st,mid,encCost,flatCost,pref)+ans(mid,en,encCost,flatCost,pref));
    }
    long long minCost(string s, int encCost, int flatCost) {
        int n=s.size();
        vector<int> pref(n+1);
        pref[0]=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                pref[i+1]=1;
            }
            pref[i+1]+=pref[i];
        }

        return ans(0,n,encCost,flatCost,pref);
    }
};