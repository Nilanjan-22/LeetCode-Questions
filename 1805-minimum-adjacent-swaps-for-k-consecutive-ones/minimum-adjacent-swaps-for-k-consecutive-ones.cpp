class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        if(k==1)return 0;
        vector<long long> ones;
        for(long long i=0;i<nums.size();i++){
            if(nums[i]==1)ones.push_back(i);
        }

        long long l=0,r=0+k-1;

        long long ans=0, distance=INT_MAX;
        while(r<ones.size()){
            long long mid= l+(k-1)/2;
            if(distance==INT_MAX){
                for(int i=l; i<mid;i++){
                    ans+=ones[mid]-ones[i];
                }
                for(int i=mid+1 ;i<=r ;i++){
                    ans+=ones[i]-ones[mid];
                }
                long long sum=(mid-l)*(mid-l+1);
                if(k%2==0){
                    ans-=r-mid;
                }
                ans-=sum;
                distance=ans;
            }
            else{
                long long change=ones[mid]-ones[mid-1]-1;
                long long lb=mid-l,rb=r-mid;
                distance-=ones[mid-1]-ones[l-1]-lb;
                distance+=change*(lb-rb);
                distance+=ones[r]-ones[mid]-rb;
                ans=min(ans,distance);
            }
            r++;
            l++;
        }

        return ans;
    }
};