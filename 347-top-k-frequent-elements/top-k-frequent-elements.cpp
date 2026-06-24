class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freqHash;
        int n=nums.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            freqHash[nums[i]]++;
        }
        for(auto it: freqHash){
            pq.push({it.second,it.first});
        }

        vector<int> ans;
        while(k>0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return ans;
    }
};