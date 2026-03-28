class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int ans=101,pos1=-1,pos2=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)pos1=i;
            else if(nums[i]==2)pos2=i;

            if(pos1!=-1 && pos2!=-1)ans=min(ans,abs(pos1-pos2));
        }
        if(ans==101)return -1;
        else return ans;
    }
};