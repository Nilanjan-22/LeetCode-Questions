class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<int> numPresent(1e5+2,0);
        for(auto it: nums){
            numPresent[it]=1;
        }
        vector<vector<int>> ans;
        int st=lower;
        while(st<=upper){
            if(numPresent[st]==0){
                int en=st;
                while(numPresent[en]==0 && en<=upper){
                    en++;
                }
                ans.push_back({st,en-1});
                st=en;
            }
            st++;
        }
        return ans;
        
    }
};