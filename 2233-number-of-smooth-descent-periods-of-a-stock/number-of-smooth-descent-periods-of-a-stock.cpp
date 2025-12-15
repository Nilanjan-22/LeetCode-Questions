class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long cnt=1, ans=0;
        for(int i=0;i<prices.size()-1;i++){
            if(prices[i]-1==prices[i+1])cnt++;
            else {
                ans+=((cnt)*(cnt+1))/2;
                cnt=1;
            }
        }
        ans+=((cnt)*(cnt+1))/2;
        return ans;
    }
};