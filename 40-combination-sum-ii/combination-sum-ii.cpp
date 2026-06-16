class Solution {
public:
    void allCombination(int i,int target, vector<vector<int>>& ans, vector<int>& temp,vector<int>& candidates){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i>=candidates.size() || target<0)return;

        int next=i;
        while(next<candidates.size() && candidates[i]==candidates[next])next++;

        temp.push_back(candidates[i]);
        allCombination(i+1,target-candidates[i],ans,temp,candidates);
        temp.pop_back();
        allCombination(next,target,ans,temp,candidates);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        allCombination(0,target,ans,temp,candidates);
        return ans;
    }
};