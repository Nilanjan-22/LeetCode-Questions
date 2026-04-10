class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int ans=1e9;
        vector<int> temp;
        for(auto it: mp){
            temp=it.second;
            if(temp.size()>2){
                for(int i=0;i<temp.size()-2;i++){
                    ans=min(ans,2*(temp[i+2]-temp[i]));
                }
            }
        }

        if(ans==1e9)return -1;
        return ans;
    
    }
};