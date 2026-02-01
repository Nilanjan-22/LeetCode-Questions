class RideSharingSystem {
public:
    queue<int> rider_q,driver_q;
    set<int> rider;
    RideSharingSystem() {
    }
    
    void addRider(int riderId) {
        rider_q.push(riderId);
        rider.insert(riderId);
    }
    
    void addDriver(int driverId) {
        driver_q.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(rider.size()==0 || driver_q.empty())return {-1,-1};
        while(!rider_q.empty() && rider.find(rider_q.front())==rider.end())rider_q.pop();

        vector<int> ans= {driver_q.front(),rider_q.front()};
        rider.erase(rider_q.front());
        driver_q.pop();
        rider_q.pop();
        return ans;
    }
    
    void cancelRider(int riderId) {
        rider.erase(riderId);
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */