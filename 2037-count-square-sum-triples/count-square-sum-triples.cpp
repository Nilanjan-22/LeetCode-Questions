class Solution {
public:
    int countTriples(int n) {
        int ans=0;
        for(int i=1;i<n;i++){
            for(int j=1; j<n; j++){
                int sum =i*i + j*j;
                if((double)sqrt(sum)== (double)floor(sqrt(sum)) && sqrt(sum)<=n)ans++;
            }
        }
        return ans;
    }
};