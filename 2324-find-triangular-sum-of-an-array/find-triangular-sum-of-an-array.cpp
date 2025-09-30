class Solution {
public:

    int triangularSum(vector<int>& nums) {
        vector<int> prev=nums;
        vector<int> next;
        while(prev.size()>1){
            for(int i=0;i<prev.size()-1;i++){
                next.push_back((prev[i]+prev[i+1])%10);
            }
            prev=next;
            next.clear();
        }
        return prev[0]%10;
    }
};