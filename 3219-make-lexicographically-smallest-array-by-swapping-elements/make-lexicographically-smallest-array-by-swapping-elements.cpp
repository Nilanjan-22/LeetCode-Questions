class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> temp;
        for(int i=0;i<nums.size();i++){
            temp.push_back({nums[i],i});
        }
        sort(temp.begin(),temp.end());
        vector<vector<int>> connected;
        vector<int> itr;
        itr.push_back(temp[0].second);
        for(int i=1;i<nums.size();i++){
            if(temp[i-1].first+limit>=temp[i].first){
                itr.push_back(temp[i].second);
            }
            else{
                connected.push_back(itr);
                itr.clear();
                itr.push_back(temp[i].second);
            }
        }
        connected.push_back(itr);
        vector<int> ans(nums.size());
        
        for(auto it: connected){
            vector<int> vec = it;
            sort(vec.begin(),vec.end());

            int n=vec.size();
            for(int i=0;i<n;i++){
                ans[vec[i]]=nums[it[i]];
            }
        }
        return ans;
    }
};