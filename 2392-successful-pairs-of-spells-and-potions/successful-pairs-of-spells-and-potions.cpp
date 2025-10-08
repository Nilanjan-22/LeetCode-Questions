class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size(), m=potions.size();
        sort(potions.begin(),potions.end());

        vector<int> pairs(n);

        //simply do bs
        for(int i=0;i<n;i++){
            int low=0,high=m-1;
            int f=m;
            while(low<=high){
                int mid=(low+high)/2;
                long long mul = (long long)spells[i]*(long long)potions[mid];
                if(mul>=success){
                    high=mid-1;
                    f=mid;
                }
                else low=mid+1;
            }
            pairs[i]=m-f;
        }
        return pairs;
    }
};