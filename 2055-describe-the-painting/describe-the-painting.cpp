class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<long long,long long> events;
        for(int i=0;i<segments.size();i++){
            long long st=segments[i][0],en=segments[i][1],c=segments[i][2];
            events[st]+=c;
            events[en]-=c;
        }
        vector<vector<long long>> ans;

        long long sum=0;
        long long st=-1;
        for(auto it:events ){
            if(sum!=0){
                ans.push_back({st,it.first,sum});
            }
            sum+=it.second;
            st=it.first;
        }
        return ans;
    }
};