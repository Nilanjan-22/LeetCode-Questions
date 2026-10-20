class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n=shifts.size(), m=tasks.size();
        vector<int> unfinished(n);
        vector<long long> taskSum(m,0);

        taskSum[0]=tasks[0];
        for(int i=1;i<m;i++){
            taskSum[i]=(long long)tasks[i]+taskSum[i-1];
        }

        long long alreadyFinished=0;
        for(int i=0;i<n;i++){
            long long sDur = shifts[i];
            int finishedTasks = upper_bound(taskSum.begin(),taskSum.end(), sDur+alreadyFinished) - taskSum.begin();
            alreadyFinished = sDur+alreadyFinished;
            if(alreadyFinished>=taskSum[m-1])alreadyFinished=0;
            unfinished[i]=m-finishedTasks;
            
        }
        return unfinished;
    }
};