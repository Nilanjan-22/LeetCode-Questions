class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        vector<bool> is_prime(1e5+1,true);
        for(int i=2; i*i<=1e5;i++){
            if(is_prime[i]){
                for(int j=i*i;j<=1e5;j+=i){
                    is_prime[j]=false;
                }
            }
        }
        set<int> prime;
        for(int i=2;i<1e5+1;i++){
            if(is_prime[i])prime.insert(i);
        }
        // return prime.size();
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(prime.find(nums[i])!=prime.end()) continue;
            else{
                for(auto it: prime){
                    if(nums[i]%it==0 && ((prime.find(nums[i]/it)!=prime.end()&& (nums[i]/it)!=it)||(nums[i]/it == pow(it,2)))){
                        sum+=nums[i]+1;
                        sum+=it;
                        sum+=nums[i]/it;
                        break;
                    }
                }
            }
        }
        return sum;

    }
};