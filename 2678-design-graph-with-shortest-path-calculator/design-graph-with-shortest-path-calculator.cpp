class Graph {
public:
    vector<vector<pair<int,int>>> adj;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    int n;
    Graph(int n, vector<vector<int>>& edges) {
        this->n=n;
        adj.resize(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> cost(n,1e9);
        pq={};
        pq.push({0,node1});
        while(!pq.empty()){
            int u=pq.top()[1];
            int c=pq.top()[0];
            pq.pop();
            if(u==node2)return c;
            for(auto it: adj[u]){
                if(cost[it.first]>it.second+c){
                    cost[it.first]=it.second+c;
                    pq.push({it.second+c,it.first});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */