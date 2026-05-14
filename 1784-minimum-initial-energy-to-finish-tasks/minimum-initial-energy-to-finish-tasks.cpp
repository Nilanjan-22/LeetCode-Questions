class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[1]-a[0] > b[1]-b[0];
        });

        int minEffort = 0;
        int curEnergy = 0;
        for(int i=0;i<tasks.size();i++){
            if(curEnergy < tasks[i][1]){
                minEffort += (tasks[i][1]-curEnergy);
                curEnergy+=(tasks[i][1]-curEnergy);
            }
            curEnergy-=tasks[i][0];
        }

        return minEffort;
        
    }
};