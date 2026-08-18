class Solution {
public:
    int findMaxPossible(char ch, vector<int>& matching, map<char,vector<int>>& app, int reqSize, int prev){
        int low = upper_bound(app[ch].begin(), app[ch].end(), prev)-app[ch].begin();
        int hi = app[ch].size()-1;
        int ans=-1;
        while(low<=hi){
            int mid = (low+hi)/2;
            if(matching[app[ch][mid]]>=reqSize){
                ans=app[ch][mid];
                low=mid+1;
            }
            else{
                hi=mid-1;
            }
        }

        return ans-prev;
    }
    int maximumGap(string skill, string station) {
        int n=station.size(), m=skill.size();
        vector<int> matching(n);
        int it=m-1;
        for(int i=n-1;i>=0;i--){
            if(it==-1){
                matching[i] = m;
                continue;
            }
            if(station[i]==skill[it]){
                matching[i]=m-it;
                it--;
            }
            else{
                if(i!=n-1)matching[i]=matching[i+1];
            }
        }
        map<char,vector<int>> app;
        for(int i=0;i<n;i++){
            app[station[i]].push_back(i);
        }
        
        int firstApp=-1;
        for(int i=0;i<n;i++){
            if(station[i]==skill[0]){
                firstApp=i;
                break;
            }
        }
        int reqSize = m-1;
        int maxLen=0;
        int prev=firstApp;
        for(int i=firstApp+1;i<n;i++){
            if(reqSize==0)break;
            if(station[i]==skill[m-reqSize]){
                maxLen = max(maxLen, findMaxPossible(station[i],matching,app,reqSize, prev));
                reqSize--;
                prev=i;
            }
        }    
        return maxLen;   

    }
};