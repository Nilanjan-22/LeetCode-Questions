class Solution {
public:
    int m=1e9+7;
    int specialTriplets(vector<int>& nums) {
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        int l=maxi*2;
        vector<long long> lc(l+1,0),rc(l+1,0);

        for(int i=0;i<nums.size();i++){
            if(nums[i]<=l)rc[nums[i]]++;
        }

        long long ans=0;
        for(int i=0;i<nums.size();i++){
            int k=nums[i];
            rc[k]--;
            long long need=(long long)2*k;

            if(need<=l){
                ans=(ans+lc[need]*rc[need])%m;
            }
            lc[k]++;
        }

        return (int)ans;
    }
};