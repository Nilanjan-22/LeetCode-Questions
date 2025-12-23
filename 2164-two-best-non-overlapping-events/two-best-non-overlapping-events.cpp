class Solution {
public:
    
    int maxTwoEvents(vector<vector<int>>& events) {
        
        sort(events.begin(),events.end());

        int ans=0, prev=0;

        priority_queue<pair<int,int> , vector<pair<int,int>> ,greater<pair<int,int>>> pq;

        for(int i=0;i<events.size();i++){
            int st=events[i][0];
            int et=events[i][1];
            int val= events[i][2];

            while(!pq.empty() && pq.top().first<st){
                prev=max(prev,pq.top().second);
                pq.pop();
            }

            ans=max(ans,val+prev);
            pq.push({et,val});
        }
        return ans;

    }
};