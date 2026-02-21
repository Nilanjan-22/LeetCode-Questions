class MyCalendarThree {
public:
    map<int,int> events;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        events[startTime]++;
        events[endTime]--;

        int ans=0,sum=0;
        for(auto it: events){
            sum+=it.second;
            ans=max(sum,ans);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */