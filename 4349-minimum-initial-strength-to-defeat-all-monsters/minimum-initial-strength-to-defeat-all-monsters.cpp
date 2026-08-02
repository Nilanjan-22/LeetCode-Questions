class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n=monsters.size();
        vector<long long> bonuses(n,0);
        for(auto v: boosts){
            bonuses[v[0]]+=(long long)v[2];
            if(v[1]+1<n){
                bonuses[v[1]+1]-=(long long)v[2];
            }
        }
        for(int i=1;i<n;i++){
            bonuses[i]+=bonuses[i-1];
        }
        
        long long minLifeNeeded=0;
        bool found=false;
        for(int i=n-1;i>=0;i--){
            if(found)minLifeNeeded+=(long long)monsters[i];
            else if(bonuses[i]<monsters[i]){
                minLifeNeeded+=(long long)monsters[i]-(long long)bonuses[i];
                found=true;
            }
        }
        return minLifeNeeded;


    }
};