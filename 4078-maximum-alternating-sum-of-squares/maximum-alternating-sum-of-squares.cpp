class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(auto& it: nums){
            if(it<0)it*=-1;
        }
        sort(nums.begin(),nums.end());
        long long ans=0;
        int mid=n/2;
        int i=0;
        while(i<n){
            if(i<mid){
                ans-=pow(nums[i],2);
            }
            else{
                ans+=pow(nums[i],2);
            }
            i++;
        }
        return ans;
    }
};