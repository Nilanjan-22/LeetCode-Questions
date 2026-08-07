class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        if(k==0)return;
        int ind=0;
        int st=0;
        int it=gcd(k,n);
        while(it--){
            while(true){
                ind+=k;
                ind%=n;
                swap(nums[ind],nums[st]);
                if((ind+k)%n ==st){
                    st++;
                    ind=st;
                    break;
                }
            }
        }
        
    }
};