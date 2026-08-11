class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int seqSum=nums[0];
        bool disconnected=false;
        set<int> hash;
        hash.insert(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1 && !disconnected)seqSum+=nums[i];
            else{
                disconnected=true;
            }
            hash.insert(nums[i]);
        }

        while(hash.find(seqSum)!=hash.end()){
            seqSum++;
        }
        return seqSum;
    }
};