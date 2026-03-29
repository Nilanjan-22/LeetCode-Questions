class EventManager {
public:
    unordered_map<int,int> eventPriority;
    map<int,set<int>> priorityCount;
    EventManager(vector<vector<int>>& events) {
        for(int i=0;i<events.size();i++){
            int eventId=events[i][0];
            int priority=events[i][1];
            eventPriority[eventId]=priority;
            priorityCount[priority].insert(eventId);
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        int oldPriority=eventPriority[eventId];

        if(priorityCount[oldPriority].size()==1)priorityCount.erase(oldPriority);
        else priorityCount[oldPriority].erase(eventId);

        eventPriority[eventId]=newPriority;
        priorityCount[newPriority].insert(eventId);
    }
    
    int pollHighest() {
        if(priorityCount.size()==0)return -1;
        auto it = priorityCount.rbegin();
        int maxPriority = it->first;
        auto it2 = (it->second).begin();
        int maxEventId=(*it2);
        if(priorityCount[maxPriority].size()==1)priorityCount.erase(maxPriority);
        else priorityCount[maxPriority].erase(maxEventId);
        eventPriority.erase(maxEventId);
        return maxEventId;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */