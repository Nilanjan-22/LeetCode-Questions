class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int dif = abs(target[0]-start[0])+abs(target[1]-start[1]);
        if(dif%2==1)return false;
        return true;
    }
};