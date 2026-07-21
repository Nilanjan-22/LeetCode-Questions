class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<tuple<int,int,int> , vector<tuple<int,int,int>> , greater<tuple<int,int,int>>> pq;
        set<pair<int,int>> vis; 
        pq.push({0,points[0][0], points[0][1]}); 
        int minCost=0;

        while(!pq.empty()){
            tuple<int,int,int> top = pq.top();
            int dist = get<0> (top);
            int x = get<1>(top);
            int y = get<2> (top);
            pq.pop();
            if(vis.find({x,y})!=vis.end())continue;
            vis.insert({x,y});
            minCost+=dist;
            for(auto it: points){
                int nx=it[0],ny=it[1];
                if(nx==x && ny==y)continue;
                int newDist = abs(nx-x)+abs(ny-y);
                if(vis.find({nx,ny})==vis.end()){
                    pq.push({newDist, nx,ny});
                }
            }
        }

        return minCost;
    }
};