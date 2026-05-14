class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int maxi=-1;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            maxi=max(maxi,nums[i]);
        }
        if(mp[maxi]!=2)return false;
        if(n!=maxi+1)return false;
        else{
            for(auto it: mp){
                if(it.second!=1 && it.first!=maxi)return false;
            }
        }
        return true;
    }
};