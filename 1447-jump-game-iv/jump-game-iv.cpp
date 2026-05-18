class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,set<int>> paths;
        for(int i=0;i<n;i++){
            paths[arr[i]].insert(i);
        }

        vector<int> visited(n,0);

        queue<pair<int,int>>q;
        q.push({0,0});
        visited[0]=1;

        while(!q.empty()){
            int pos=q.front().first;
            int dist=q.front().second;

            q.pop();

            if(pos==n-1)return dist;

            if(pos>1 && visited[pos-1]==0){
                q.push({pos-1,dist+1});
                visited[pos-1]=1;
            }
            if(visited[pos+1]==0){
                q.push({pos+1,dist+1});
                visited[pos+1]=1;
            }

            for(auto it: paths[arr[pos]]){
                if(it!=pos && visited[it]==0){
                    q.push({it,dist+1});
                    visited[it]=1;
                    paths[arr[pos]].erase(it);
                }
            }
        }

        return n;
    }
};