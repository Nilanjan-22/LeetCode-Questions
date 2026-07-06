class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end() , [](const vector<int>& a, const vector<int>& b){
            if(a[0]==b[0])return a[1]>b[1];
            return a[0]<b[0];
        });
        int st=intervals[0][0], en=intervals[0][1];
        int totalIntervals=1;
        for(int i=1;i<intervals.size();i++){
            // if(intervals[i][0]>en){

            // }
            if(intervals[i][1]>en){
                en=intervals[i][1];
                totalIntervals++;
            }
        }

        return totalIntervals;
    }
};