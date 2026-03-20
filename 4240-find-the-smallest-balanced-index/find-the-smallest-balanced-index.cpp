class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n=nums.size();
        long long l=1e15;
        vector<long long> prefsum(n);
        prefsum[0]=0;
        for(int i=0;i<nums.size()-1;i++){
            prefsum[i+1]=prefsum[i]+(long long)nums[i];
        }

        vector<long long> prefmul(n,-1);
        prefmul[n-1]=1LL;
        for(int i=n-1;i>0;i--){
            if(l/prefmul[i] <=  nums[i])break;
            else{
                long long mul=(long long)prefmul[i]*(long long)nums[i];
                prefmul[i-1]=mul;
            }
        }

        for(int i=0;i<n;i++){
            if(prefmul[i]==-1)continue;
            else{
                if(prefmul[i]==prefsum[i])return i;
            }
        }
        return -1;
    }
};