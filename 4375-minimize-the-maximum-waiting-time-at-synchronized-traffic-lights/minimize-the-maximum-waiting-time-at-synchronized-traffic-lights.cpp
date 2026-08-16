class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int maxi=0;
        for(auto it:lights){
            maxi=max(maxi,it);
        }
        int minimumPenalty=0;
        for(int i=0;i<arrivalTime.size();i++){
            int r = arrivalTime[i]%period;
            if(r>=maxi)minimumPenalty = max(minimumPenalty, period-r);
        }
        return minimumPenalty;
    }
};