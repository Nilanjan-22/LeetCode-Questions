class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> road(1001,0);
        for(int i=0;i<trips.size();i++){
            int f=trips[i][1],t=trips[i][2],del=trips[i][0];
            road[f]+=del;
            road[t]-=del;
        }   

        int sum=0;
        for(int i=0;i<1001;i++){
            sum+=road[i];
            if(sum>capacity)return false;
        }
        return true;
    }
};