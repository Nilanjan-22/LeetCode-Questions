class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n=tasks.size(), m=shifts.size();
        map<long long,int> prefixTime;
        long long sum=0;
        for(int i=0; i<n; i++){
            sum+=(long long)tasks[i];
            prefixTime[sum]=i+1;
        }

        vector<int> unfinishedTask(m);

        long long overallTime=0;
        for(int i=0;i<m;i++){
            overallTime+=(long long)shifts[i];
            if(overallTime>=sum){
                unfinishedTask[i]=0;
                overallTime=0;
                continue;
            }
            auto finishedTasks = prefixTime.upper_bound(overallTime);
            if(finishedTasks == prefixTime.begin()){
                unfinishedTask[i]=n;
                continue;
            }
            finishedTasks--;
            unfinishedTask[i] = n-finishedTasks->second;
        }
        return unfinishedTask;
    }
};