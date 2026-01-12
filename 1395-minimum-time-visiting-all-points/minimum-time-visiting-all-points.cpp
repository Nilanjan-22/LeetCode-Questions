class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        int si=points[0][0], sj=points[0][1];
        for(int it=0;it<points.size();it++){
            int i=points[it][0],j=points[it][1];
            ans+=max(abs(si-i),abs(sj-j));
            si=i,sj=j;
        }
        return ans;
    }
};