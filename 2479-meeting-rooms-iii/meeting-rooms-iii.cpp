class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> cnt(n,0);

        priority_queue<int , vector<int> , greater<int>> room;
        priority_queue<pair<long long,int>, vector<pair<long long,int>> , greater<pair<long long,int>>> busy;

        for(int i=0;i<n;i++)room.push(i);

        sort(meetings.begin(),meetings.end());

        for(int i=0;i<meetings.size();i++){
            long long duration = meetings[i][1]-meetings[i][0];
            long long start=meetings[i][0];

            while(!busy.empty() && busy.top().first<=start){
                room.push(busy.top().second);
                busy.pop();
            }

            if(!room.empty()){
                int roomindex=room.top();
                room.pop();
                cnt[roomindex]++;

                busy.push({start+duration,roomindex});
            }
            else{
                int roomindex=busy.top().second;
                long long time=busy.top().first;

                cnt[roomindex]++;
                busy.pop();
                busy.push({time+duration,roomindex});
            }
        }

        int mostbook=-1,maxi=-1;
        for(int i=0;i<n;i++){
            if(maxi<cnt[i]){
                maxi=cnt[i];
                mostbook=i;
            }
        }

        return mostbook;
    }
};