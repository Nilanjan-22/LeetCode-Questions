class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<long long> prefgcd(n);
        int maxi=-1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            prefgcd[i] = gcd(maxi,nums[i]);
        }
        sort(prefgcd.begin(),prefgcd.end());
        long long sum=0;
        int lo=0,hi=n-1;
        while(lo<hi){
            sum+=gcd(prefgcd[lo],prefgcd[hi]);
            lo++;
            hi--;
        }

        return sum;
    }
};