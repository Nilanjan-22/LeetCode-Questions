class MyCalendar {
public:
    vector<vector<int>> time;
    MyCalendar() {
    }
    
    bool book(int startTime, int endTime) {
        for(int i=0;i<time.size();i++){
            int st=time[i][0],en=time[i][1];
            if( startTime>=en || endTime<=st )continue;
            else return false;
        }
        time.push_back({startTime,endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */