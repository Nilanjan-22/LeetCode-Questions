class Solution {
public:
    bool predict(int turn, int score1, int score2, int i, int j, vector<int>& nums){
        if(j<i)return score2<=score1;

        if(turn == 0){
            return predict(1,score1+nums[i],score2,i+1,j,nums) || predict(1,score1+nums[j],score2,i,j-1,nums);
        }
        else{
            return predict(0,score1,score2+nums[i],i+1,j,nums) && predict(0,score1,score2+nums[j],i,j-1,nums);
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        
        int n=nums.size();
        return predict(0,0,0,0,n-1,nums);

    }
};