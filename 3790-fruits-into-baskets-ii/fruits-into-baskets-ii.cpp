class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans=0;
        int n=baskets.size();
        vector<int> fill(n,0);
        for(int i=0;i<fruits.size();i++){
            bool placed=false;
            for(int j=0; j<n;j++){
                if(baskets[j]>=fruits[i] && fill[j]==0){
                    fill[j]=1;
                    placed=true;
                    break;
                }
            }
            if(!placed)ans++;
        }
        return ans;
    }
};