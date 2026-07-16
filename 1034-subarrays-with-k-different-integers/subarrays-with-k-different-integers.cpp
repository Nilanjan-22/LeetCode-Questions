class Solution {
public:
    int countSubarrays(vector<int>& nums, int k){
        int l=0,r=0;
        int cnt=0;
        map<int,int> freq;
        while(r<nums.size()){
            while(r<nums.size() && freq.size()<k){
                freq[nums[r]]++;
                r++;
            }
            while(freq.size()==k){
                cnt+=r-l-1;
                freq[nums[l]]--;
                if(freq[nums[l]]==0)freq.erase(nums[l]);
                l++;
            }
        }
        int len=r-l;
        cnt+=(len*(len+1))/2;
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        cout<<countSubarrays(nums,k);
        return countSubarrays(nums,k+1)-countSubarrays(nums,k);
    }
};