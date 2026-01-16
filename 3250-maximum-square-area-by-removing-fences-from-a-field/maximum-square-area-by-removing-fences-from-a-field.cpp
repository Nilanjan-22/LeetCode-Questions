class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        long long ans=-1;
        int mod=1e9+7;
        unordered_map<int,int> mp; //diff, first occurence
        hFences.push_back(m);
        hFences.push_back(1);
        vFences.push_back(n);
        vFences.push_back(1);
        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());
        for(int i=0;i<hFences.size();i++){
            long long h=hFences[i];
            for(int j=0;j<vFences.size();j++){
                long long v=vFences[j];

                if(mp.find(h-v)==mp.end())mp[h-v]=h;
                else {
                    long long fh=mp[h-v];
                    ans=max(ans,h-fh);
                }
            }
        }
        if(ans==-1 || ans==0)return-1; 
        return ans*ans%mod;

    }
};