class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf=0;
        int buy=INT_MAX;
        int prof=0;
        for(int i=0;i<prices.size();i++){
            if(buy>prices[i]){
                prof=0;
                buy=prices[i];
            }
            else {
                prof=prices[i]-buy;
                maxProf=max(maxProf,prof);
            }
        }
        return maxProf;
    }
};