class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long nw=0, mw=0;
        long long profit=0;

        for(int i=0;i<prices.size();i++){
            profit +=prices[i]*strategy[i];
            if(i<k){
                nw=profit;
                if(i>=k/2){
                    mw+=prices[i];
                }
            }
            
        }

        long long maxinc=max(0LL,mw-nw);

        for(int st=1; st<=prices.size()-k; st++){
            //change nw
            nw-=prices[st-1]*strategy[st-1];
            nw+=prices[st+k-1]*strategy[st+k-1];
            //change mw
            mw-=prices[st+(k/2)-1];
            mw+=prices[st+k-1];

            maxinc=max(mw-nw, maxinc);
        }
        return profit+maxinc;
    }
};