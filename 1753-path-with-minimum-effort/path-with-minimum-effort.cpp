class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        //since it is a weighted graph use dijkstra
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        // take all possibilites
        vector<int> mi={0,0,1,-1};
        vector<int> mj={-1,1,0,0};
        vector<vector<int>> mef(n,vector<int>(m,1e9));

        pq.push({0,0,0});
        mef[0][0]=0;
        while(!pq.empty()){
            int i=pq.top()[1];
            int j=pq.top()[2];
            int h=heights[i][j];
            int me=pq.top()[0];

            pq.pop();
            for(int it=0;it<4;it++){
                int i1=i+mi[it], j1=j+mj[it];
                if(i1>-1 && i1<n && j1>-1 && j1<m){
                    if(mef[i1][j1]>max(abs(heights[i1][j1]-h),me)){
                        if(abs(heights[i1][j1]-h)>me){
                            mef[i1][j1]=abs(heights[i1][j1]-h);
                        }
                        else mef[i1][j1]=me;
                        pq.push({mef[i1][j1],i1,j1});
                    }
                }
            }
        }
        return mef[n-1][m-1];
    }
};