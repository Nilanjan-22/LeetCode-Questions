class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool isOddPresent=false;
        int mini=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==1){
                isOddPresent=true;
            }
            mini = min(nums1[i],mini);
        }
        if(isOddPresent && mini%2==0)return false;
        return true;
        

    }
};