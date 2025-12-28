class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        long long ans=0;
        if(cost1+cost2>=costBoth){
            ans+=min((long long)need1,(long long)need2)*(long long)costBoth;
            if(need1>need2){
                if(cost1>costBoth)ans+=(long long)(need1-need2)*(long long)costBoth;
                else ans+=(long long)(need1-need2)*(long long)cost1;
            }
            else{
                if(cost2>costBoth)ans+=(long long)(need2-need1)*(long long)costBoth;
                else ans+=(long long)(need2-need1)*(long long)cost2;
            }
        }
        else{
            ans+=(long long)cost1*(long long)need1;
            ans+=(long long)cost2*(long long)need2;
        }

        return ans;
    }
};