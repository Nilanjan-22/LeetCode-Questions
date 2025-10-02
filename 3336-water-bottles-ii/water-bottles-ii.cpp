class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        //do complete simulation

        int ans=numBottles;
        int empty=numBottles;
        numBottles=0;
        while(empty>=numExchange){
            while(empty>=numExchange){
                empty-=numExchange;
                numBottles++;
                numExchange++;
            }
            ans+=numBottles;
            empty+=numBottles;
            numBottles=0;
        }
        return ans;
    }
};