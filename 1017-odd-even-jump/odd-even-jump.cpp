class Solution {
public:
    int n;
    vector<int> ngi; //for odd jumps (0)
    vector<int> nsi; //for even jumps (1)
    vector<vector<int>> dp;
    int ans(int i, int jump){
        if(i==n)return 1;
        if(i==-1)return 0;
        if(dp[i][jump]!=-1)return dp[i][jump];
        if(jump==0){
            return dp[i][jump]=ans(ngi[i],1);
        }
        else return dp[i][jump]= ans(nsi[i],0);
    }
    int oddEvenJumps(vector<int>& arr) {
        n=arr.size()-1;
        ngi.resize(n);
        nsi.resize(n);
        dp.resize(n,vector<int>(2,-1));
        map<int,int> mp;
        mp[arr[n]]=n;
        for(int i=n-1;i>=0;i--){
            auto it = mp.lower_bound(arr[i]);
            if(it==mp.end()){
                ngi[i]=-1;
            }
            else{
                ngi[i]=(*it).second;
            }
            mp[arr[i]]=i;
        }
        
        mp.clear();
        mp[-arr[n]]=n;
        for(int i=n-1;i>=0;i--){
            auto it = mp.lower_bound(-arr[i]);
            if(it==mp.end()){
                nsi[i]=-1;
            }
            else{
                nsi[i]=(*it).second;
            }
            mp[-arr[i]]=i;
        }

        int goodstart=0;
        for(int i=0;i<n+1;i++){
            goodstart+=ans(i,0);
        }
        return goodstart;
    }
};