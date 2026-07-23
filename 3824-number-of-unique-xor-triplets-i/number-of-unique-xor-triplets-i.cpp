class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return n;
        int power = 0;
        while(n>0){
            n/=2;
            power++;
        }
        int ans = 1<<power;
        return ans;
    }
};