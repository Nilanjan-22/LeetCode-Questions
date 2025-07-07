class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n=events.size();
        priority_queue<int,vector<int>,greater<int>> mini;
        int max_day=0, e=0;
        for(int i=0;i<n;i++)max_day=max(max_day,events[i][1]);
        int day=1;
        int ans=0;
        while(day<=max_day){

            while(e<n && events[e][0]==day){
                mini.push(events[e][1]);
                e++;
            }

            while(!mini.empty() && mini.top()<day){
                mini.pop();
            }

            if(!mini.empty()){
                mini.pop();
                ans++;
            }
            day++;
        }
        return ans;
    }
};