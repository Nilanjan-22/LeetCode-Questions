class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        vector<vector<pair<int,int>>> sortedTimes(2), minDuration(2);
        int n=landStartTime.size(), m=waterStartTime.size();
        for(int i=0;i<max(n,m);i++){
            if(i<n)sortedTimes[0].push_back({landStartTime[i],landStartTime[i]+landDuration[i]});
            if(i<m)sortedTimes[1].push_back({waterStartTime[i], waterStartTime[i]+waterDuration[i]});
        }
        sort(sortedTimes[0].begin(),sortedTimes[0].end());
        sort(sortedTimes[1].begin(),sortedTimes[1].end());

        int minBefore1=INT_MAX,minBefore2=INT_MAX, minAfter1=INT_MAX, minAfter2=INT_MAX;
        for(int i=0;i<max(n,m);i++){
            if(i<n){
                minBefore1=min(minBefore1, sortedTimes[0][i].second-sortedTimes[0][i].first);
                minAfter1=min(minAfter1, sortedTimes[0][n-1-i].second);

                minDuration[0].push_back({minBefore1,minAfter1});
            }

            if(i<m){
                minBefore2=min(minBefore2, sortedTimes[1][i].second-sortedTimes[1][i].first);
                minAfter2=min(minAfter2, sortedTimes[1][m-1-i].second);

                minDuration[1].push_back({minBefore2,minAfter2});
            }
        }


        int minTime=INT_MAX;
        for(int i=0;i<n;i++){
            int time=sortedTimes[0][i].second;
            auto it=lower_bound(sortedTimes[1].begin(),sortedTimes[1].end(),pair<int, int>{time,0});
            int ind=it-sortedTimes[1].begin();
            int minAdd=INT_MAX;
            if(ind>0)minAdd=min(minDuration[1][ind-1].first,minAdd);
            if(ind<m)minAdd=min(minDuration[1][m-1-ind].second-time,minAdd);
            time+=minAdd;

            minTime=min(minTime,time);
        }

        for(int i=0;i<m;i++){
            int time=sortedTimes[1][i].second;
            auto it=lower_bound(sortedTimes[0].begin(),sortedTimes[0].end(),pair<int, int>{time,0});
            int ind=it-sortedTimes[0].begin();
            int minAdd=INT_MAX;
            if(ind>0)minAdd=min(minDuration[0][ind-1].first,minAdd);
            if(ind<n)minAdd=min(minDuration[0][n-1-ind].second-time,minAdd);
            time+=minAdd;

            minTime=min(minTime,time);
        }

        return minTime;
    }
};