class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans=0;
        int mini=0;
        for(int i=0;i<target.size();i++){
            if(mini<target[i]){
                ans+=target[i]-mini;
                mini=target[i];
            }
            else mini=min(mini,target[i]);
        }
        return ans;
    }
};