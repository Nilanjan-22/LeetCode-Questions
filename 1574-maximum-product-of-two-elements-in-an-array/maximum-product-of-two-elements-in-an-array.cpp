class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi1=INT_MIN, maxi2=INT_MIN;
        for(auto num: nums){
            if(num>maxi1){
                maxi2=maxi1;
                maxi1=num;
            }
            else if(num>maxi2)maxi2=num;
        }
        return (maxi1-1)*(maxi2-1);
    }
};