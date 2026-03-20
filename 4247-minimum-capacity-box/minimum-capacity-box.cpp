class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int minInd=-1;
        for(int i=0;i<capacity.size();i++){
            if(capacity[i]>=itemSize){
                if(minInd==-1)minInd=i;
                else{
                    if(capacity[i]<capacity[minInd])minInd=i;
                }
            }
        }

        return minInd;
    }
};