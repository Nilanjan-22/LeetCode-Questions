class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int ans=-1, maxi=-1;
        vector<int> years(2051,0);
        for(int i=0;i<logs.size();i++){
            int b=logs[i][0],d=logs[i][1];
            years[b]++;
            years[d]--;
        }
        int population=0;
        for(int i=1950;i<2051;i++){
            population+=years[i];
            if(population>maxi){
                maxi=population;
                ans=i;
            }
        }
        return ans;
    }
};