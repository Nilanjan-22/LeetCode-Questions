class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // if(k==0)return 0;
        int n=nums.size();
        int ans=(n*(n+1))/2;
        
        int mul=1,l=0,r=0,prevr=-1;
        
        while(r<nums.size() && l<=r){
            if(r!=prevr){
                mul*=nums[r];
                prevr=r;
            }

            if(mul<k)r++;
            else{
                ans-=nums.size()-r;
                mul/=nums[l];
                l++;
                if(l>r)r++;
            }
        }
        return ans;


    }
};