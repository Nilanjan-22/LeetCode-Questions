class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int mini=complexity[0];
        for(int i=1;i<complexity.size();i++){
            if(complexity[i]<=mini)return 0;
        }
        int m=1e9+7;
        int n=complexity.size()-1;
        long long ans=1;
        while(n>0){
            ans*=n;
            ans%=m;
            n--;
        }
        return (int)ans;
    }
};