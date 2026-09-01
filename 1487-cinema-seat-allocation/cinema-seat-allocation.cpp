class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(),reservedSeats.end());
        map<int,vector<int>> reserved;
        for(auto it: reservedSeats){
            int row = it[0];
            int seat = it[1];
            if(seat!=1 && seat!=10){
                reserved[row].push_back(seat);
            }
        }
        int vacantRows = n-reserved.size();
        int maximumGroups = vacantRows*2;
        for(auto itr: reserved){
            vector<int> it = itr.second;
            int occurenceOf4 = lower_bound(it.begin(),it.end(),4)-it.begin();
            int occurenceOf6 = lower_bound(it.begin(),it.end(),6)-it.begin();
            int occurenceOf8 = lower_bound(it.begin(),it.end(),8)-it.begin();
            int occurenceOf10 = lower_bound(it.begin(),it.end(),10)-it.begin();

            if(occurenceOf6==0 || occurenceOf8-occurenceOf4==0 || occurenceOf10-occurenceOf6==0){
                maximumGroups++;
            }
        }
        return maximumGroups;
    }
};