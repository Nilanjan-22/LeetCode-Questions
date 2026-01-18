class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n=costs.size();
        vector<vector<int>> v(n,vector<int>(2));
        for(int i=0;i<n;i++){
            v[i][0]=costs[i];
            v[i][1]=capacity[i];
        }

        sort(v.begin(),v.end());
        vector<int> maxi(n);
        int m=-1;
        for(int i=0;i<n;i++){
            m=max(m,v[i][1]);
            maxi[i]=m;
        }

        int ans=0;
        for(int i=n-1;i>=0;i--){
            if(v[i][0]>budget-1)continue;

            int lo=0, hi=i-1, pos=-1;
            while(lo<=hi){
                int mid=(lo+hi)/2;
                if(v[mid][0]>budget-v[i][0]-1)hi=mid-1;
                else{
                    pos=mid;
                    lo=mid+1;
                }
            }
            if(pos==-1)ans=max(ans,v[i][1]);
            else ans=max(ans,v[i][1]+maxi[pos]);
        }
        return ans;
    }
};