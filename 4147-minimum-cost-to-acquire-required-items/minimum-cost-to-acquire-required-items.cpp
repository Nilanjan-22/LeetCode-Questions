class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long buyBoth = (long long)costBoth*(long long)max(need1,need2);
        long long buyDiff = (long long)cost1*(long long)need1 + (long long)cost2*(long long)need2;
        long long hybrid = (long long)costBoth *(long long)min(need1,need2);
        if(need1>need2){
            hybrid+=(long long)cost1*(long long)(need1-need2);
        }
        else{
            hybrid +=(long long)cost2*(long long)(need2-need1);
        }
        return min(buyBoth,min(buyDiff,hybrid));
    }
};