class AuctionSystem {
public:
    map<pair<int,int>, int> mp;
    map<int, set<pair<int,int>>> bids;
    AuctionSystem() {
        
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        if(mp.find({userId,itemId})!=mp.end()){
            int c_bid=mp[{userId,itemId}];
            bids[itemId].erase({c_bid,userId});
            mp[{userId,itemId}]=bidAmount;
            bids[itemId].insert({bidAmount,userId});
        }
        else{
            mp[{userId,itemId}]=bidAmount;
            bids[itemId].insert({bidAmount,userId});
        }
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        int c_bid=mp[{userId,itemId}];
        bids[itemId].erase({c_bid,userId});
        mp[{userId,itemId}]=newAmount;
        bids[itemId].insert({newAmount,userId});
    }
    
    void removeBid(int userId, int itemId) {
        int c_bid=mp[{userId,itemId}];
        bids[itemId].erase({c_bid,userId});
        mp.erase({userId,itemId});
    }
    
    int getHighestBidder(int itemId) {
        if(bids[itemId].size()==0)return -1;
        pair<int,int> pt= *(bids[itemId]).rbegin();
        return pt.second;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */