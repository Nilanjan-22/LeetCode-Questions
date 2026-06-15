class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> alreadyIncluded;
        sort(nums.begin(),nums.end());
        for(int i=0;i<(1<<nums.size());i++){
            int temp=i;
            vector<int> sub;
            int it=0;
            while(temp>0){
                if(temp%2==1)sub.push_back(nums[it]);
                it++;
                temp/=2;
            }
            alreadyIncluded.insert(sub);
        }

        vector<vector<int>> ans;
        for(auto it: alreadyIncluded){
            ans.push_back(it);
        }

        return ans;
    }
};