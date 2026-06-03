class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int,int> time;
        for(int i=0;i<intervals.size();i++){
            time[intervals[i][0]]++;
            time[intervals[i][1]]--;
        }

        int sum=0, st=-1;
        vector<vector<int>> mergedIntervals;
        for(auto it: time){
            if(sum==0)st=it.first;
            sum+=it.second;

            if(sum==0){
                mergedIntervals.push_back({st,it.first});
            }
        }

        return mergedIntervals;
    }
};