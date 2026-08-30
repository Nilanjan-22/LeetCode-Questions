class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minInd=0,maxInd=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<nums[minInd]){
                minInd=i;
            }
            if(nums[i]>nums[maxInd]){
                maxInd=i;
            }
        }
        int size = nums.size();
        int frontDel = max(minInd,maxInd)+1;
        int backDel = max(size-minInd, size-maxInd);
        int both = min(minInd,maxInd)+1 + min(size-minInd, size-maxInd);
        return min(frontDel,min(backDel,both));
    }
};