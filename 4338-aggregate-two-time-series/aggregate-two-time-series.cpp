class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int i=0,j=0;
        vector<vector<int>> aggregatedTimeSeries;
        int t1=series1[i][0],t2=series2[j][0],v1=series1[i][1],v2=series2[j][1];
        while(i<series1.size() || j<series2.size()){
            int time = min(t1,t2);
            int val = v1+v2;

            aggregatedTimeSeries.push_back({time,val});

            if(i<series1.size() && time == t1){
                i++;
                if(i==series1.size()){
                    t1=INT_MAX;
                    v1=0;
                }
                else {
                    t1=series1[i][0];
                    v1=series1[i][1];
                }
                
            }

            if(j<series2.size() && time == t2){
                j++;
                if(j==series2.size()){
                    t2=INT_MAX;
                    v2=0;
                }
                else {
                    t2=series2[j][0];
                    v2=series2[j][1];
                }
                
            }
        }
        return aggregatedTimeSeries;
    }
};