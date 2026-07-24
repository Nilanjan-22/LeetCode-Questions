class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> uniqueXorPairs;
        int maxNum=0;
        for(int i=0;i<nums.size();i++){
            maxNum=max(maxNum,nums[i]);
            for(int j=i;j<nums.size();j++){
                uniqueXorPairs.insert(nums[i]^nums[j]);
            }
        }

        int maxXor=0;
        while(maxNum>0){
            maxNum/=2;
            maxXor*=2;
            maxXor++;
        }
       
        int cnt=0;
        for(int xr = 0; xr<=maxXor ;xr++){
            for(int i=0; i<nums.size();i++){
                int xorReq = xr^nums[i];
                if(uniqueXorPairs.find(xorReq)!=uniqueXorPairs.end()){
                    cnt++;
                    break;
                }
            }
        }
        return cnt;


    }
};