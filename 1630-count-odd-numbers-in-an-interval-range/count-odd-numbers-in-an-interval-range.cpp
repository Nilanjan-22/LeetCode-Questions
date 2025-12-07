class Solution {
public:
    int countOdds(int low, int high) {
        if(low==high){
            return (low%2==1);
        }
        int dif=high-low-1;
        int odd=0;
        if(dif%2==0)return dif/2 + 1;
        else if(low%2==0)return dif/2 +1;
        else return dif/2 + 2;
    }
};