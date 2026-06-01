class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        sort(cost.rbegin(),cost.rend());
        int minCost=0;
        for(int i=1;i<n+1;i++){
            if(i%3==0)continue;
            else minCost+=cost[i-1];
        }
        return minCost;
    }
};