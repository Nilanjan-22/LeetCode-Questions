class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> glass(5051,0);
        glass[1]=poured;
        int it=1;
        for(int i=1;i<100;i++){
            for(int j=1;j<=i;j++){
                if(glass[it]>1.00){
                    double rem=glass[it]-1.00;
                    glass[it]=1.00;
                    int left=it+i, right=it+i+1;
                    glass[left]+=rem/2;
                    glass[right]+=rem/2;            
                }
                it++;
            }
        }

        // for(int i=1;i<5051;i++){
        //     cout<<glass[i]<<" ";
        // }
        int i = ((query_row)*(query_row+1))/2 + query_glass+1;
        return glass[i];
    }
};