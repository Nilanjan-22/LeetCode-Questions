class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>> mp;
        int s=nums.size();
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int n=queries.size();
        vector<int> ans(n,-1);
        vector<int> temp;
        for(int i=0;i<n;i++){
            int num=nums[queries[i]];
            temp=mp[num];
            int size=temp.size();
            if(size==1)continue;

            int ind = lower_bound(temp.begin(),temp.end(),queries[i])-temp.begin();
            int mindist=1e9;
            if(ind!=0){
                mindist = min(s+temp[0]-queries[i] , queries[i]-temp[ind-1]);
            }
            if(ind!=size-1){
                mindist= min(mindist , temp[ind+1] - queries[i]);
                mindist = min(mindist ,s+queries[i]-temp[size-1]);
            }

            ans[i]=mindist;
        }
        return ans;
    }
};