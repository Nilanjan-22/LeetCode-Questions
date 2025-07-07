class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        // first sort according to the starting date
        sort(events.begin(),events.end()); 
        //so that i can know which event starts at which day

        //find the final day to event all events
        int fday=0;
        for(int i=0;i<n;i++)fday=max(fday,events[i][1]);

        //min heap to store the ending dates in increasing order so that we attend the event 
        //first which is ending sooner
        priority_queue<int,vector<int>, greater<int>> end_date;

        int eventNo=0,day=1,ans=0;
        while(day<=fday){

            while(eventNo<n && events[eventNo][0]==day){
                end_date.push(events[eventNo][1]);
                eventNo++;
            }

            while(!end_date.empty() && end_date.top()<day){
                end_date.pop();
            }

            if(!end_date.empty()){
                end_date.pop();
                ans++;
            }
            day++;
        }
        return ans;
    }
};