class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int ac=0,iac=1;
        vector<int> players(2,0);
        for(int i=1;i<=nums.size();i++){
            if(i%6==0){
                swap(ac,iac);
            }
            if(nums[i-1]%2==1){
                swap(ac,iac);
            }
            players[ac]+=nums[i-1];
        }
        return players[0]-players[1];

    }
};