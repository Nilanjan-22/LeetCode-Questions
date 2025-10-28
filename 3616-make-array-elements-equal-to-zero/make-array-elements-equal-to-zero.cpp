class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int total=0;
        for(int i=0;i<nums.size();i++)total+=nums[i];

        int ans=0;
        int ts=0;
        for(int i=0;i<nums.size();i++){
            ts+=nums[i];
            if(total%2==0 && ts==total/2 && nums[i]==0)ans+=2;
            else if(total%2==1 && (ts==total/2 || ts==total/2+1) && nums[i]==0 )ans+=1;
        }
        return ans;
    }
};