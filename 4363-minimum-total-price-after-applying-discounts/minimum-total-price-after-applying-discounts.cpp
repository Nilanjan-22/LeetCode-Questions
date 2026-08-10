class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(),prices.rend());
        sort(discounts.rbegin(), discounts.rend());
        double minPrice=0.0;
        for(int i=0;i<prices.size();i++){
            if(i>=discounts.size())minPrice+=prices[i];
            else minPrice += ((double)prices[i] * (100.0-(double)discounts[i]))/100.0;
        }
        return minPrice;
    }
};