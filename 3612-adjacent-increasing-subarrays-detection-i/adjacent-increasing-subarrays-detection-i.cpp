class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int los=1;
        int n=nums.size();
        if(k==1 && n>=2)return true;
        int l=1,prev=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                l++;
                if(prev>=k)los=max(los,l+k);
                else los=max(los,l);
            }
            else{
                prev=l;
                l=1;
            } 
        }
        cout<<los<<endl;
        if((los/k)>=2)return true;
        else return false;
    }
};