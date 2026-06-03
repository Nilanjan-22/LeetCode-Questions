class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        int st=-1,en=-1;
        vector<vector<int>> mergedIntervals;
        for(auto it: intervals){
            if(en<it[0]){
                if(en!=-1)mergedIntervals.push_back({st,en});
                st=it[0];
                en=it[1];
            }
            else en=max(it[1],en);
        }
        mergedIntervals.push_back({st,en});

        return mergedIntervals;
    }
};