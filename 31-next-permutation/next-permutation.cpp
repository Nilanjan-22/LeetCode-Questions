class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int start=-1;
        int it;
        int mov=-1;
        for(it=n-1;it>=1;it--){
            for(int i=it-1;i>=0;i--){
                if(nums[i]<nums[it]){
                    if(i>start)mov=it;
                    start=max(i,start);
                    break;
                }
            }
            if(start>=it)break;
        }
        if(start!=-1)swap(nums[mov],nums[start]);
        sort(nums.begin()+start+1,nums.end());
    }
};