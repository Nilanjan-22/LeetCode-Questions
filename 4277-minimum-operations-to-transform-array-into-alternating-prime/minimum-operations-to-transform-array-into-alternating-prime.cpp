class Solution {
public:
    vector<int> primes;
    vector<int> isprime;
    void getPrimes(){
        isprime.resize(2e5+1,1);
        // primes.clear();
        isprime[0] = isprime[1]=0;
        for(int num=2; num*num<=2e5;num++){
            if(isprime[num]==1){
                for(int i=num*num; i<=2e5; i+=num){
                    isprime[i]=0;
                }
            }
        }

        for(int i=2;i<2e5+1;i++){
            if(isprime[i]) primes.push_back(i);
        }
    }
    int minOperations(vector<int>& nums) {
        getPrimes();
        int minOps=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                
                int ind = lower_bound(primes.begin(),primes.end(),nums[i]) - primes.begin();
                minOps+=primes[ind]-nums[i];
            }
            else{
                int num=nums[i];
                if(isprime[num]==1){
                    if(num==2)minOps+=2;
                    else minOps++;
                }
            }
        }
        return minOps;
    }
};