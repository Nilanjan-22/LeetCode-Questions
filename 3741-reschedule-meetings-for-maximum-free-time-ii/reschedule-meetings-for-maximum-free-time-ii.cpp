class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int> free(n+1);
        set<pair<int,int>>st;
        free[0]=(startTime[0]-0);
        st.insert({free[0],0});
        for(int i=1;i<n;i++){
            free[i]=(startTime[i]-endTime[i-1]);
            st.insert({free[i],i});
        }
        free[n]=(eventTime-endTime[n-1]);
        st.insert({free[n],n});

        int ans=0;
        for(int i=0;i<n;i++){
            int add=free[i]+free[i+1];
            auto it=st.rbegin();

            while((*it).second==i || (*it).second==i+1)it++;
            if((*it).first>=(endTime[i]-startTime[i]))add+=(endTime[i]-startTime[i]);
            ans=max(ans,add);
        }
        return ans;
    }
};