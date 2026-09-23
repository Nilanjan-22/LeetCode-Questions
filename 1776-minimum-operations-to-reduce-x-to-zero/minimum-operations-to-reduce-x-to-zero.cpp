class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        map<int,int> prefSum, suffSum;
        prefSum[0]=0;
        suffSum[0]=0;
        int s1=0,s2=0;
        for(int i=0;i<n;i++){
            s1+=nums[i];
            s2+=nums[n-i-1];
            prefSum[s1]=i+1;
            suffSum[s2]=i+1;
        }
        int minSteps = 1e9;
        s1=0;
        s2=0;
        for(int i=0;i<n;i++){
            s1+=nums[i], s2+=nums[n-i-1];
            if(suffSum.find(x-s1)!=suffSum.end()){
                minSteps = min(minSteps, i+1+suffSum[x-s1]);
            }
            if(prefSum.find(x-s2)!=prefSum.end()){
                minSteps = min(minSteps, i+1+prefSum[x-s2]);
            }
        }
        return minSteps > n ? -1 : minSteps;


    }
};