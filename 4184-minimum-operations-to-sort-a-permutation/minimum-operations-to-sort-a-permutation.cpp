class Solution {
public:
    
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        //check up down up
        int mismatch=0, pos=-1;
        int move1=INT_MAX;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                mismatch++;
                pos=i+1;
            }
        }
        if(mismatch==0)return 0;
        if(mismatch==1 && nums[0]>nums[n-1])move1=min(pos, n-pos+2);

        //check down up down
        mismatch=0, pos=-1;
        int move2=INT_MAX;
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                mismatch++;
                pos=i+1;
            }
        }
        if(mismatch==0)return 1;
        if(mismatch==1 && nums[n-1]>nums[0])move2=min(pos+1, n-pos+1);

        int minMoves= min(move1,move2);
        if(minMoves==INT_MAX)return -1;
        return minMoves;
    }
};