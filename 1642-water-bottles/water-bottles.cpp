class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=0;
        ans+=numBottles;
        while(numBottles>=numExchange){
            int rem=numBottles%numExchange;
            numBottles/=numExchange;
            ans+=numBottles;
            numBottles+=rem;
        }
        // ans+=numBottles;
        return ans;
    }
};