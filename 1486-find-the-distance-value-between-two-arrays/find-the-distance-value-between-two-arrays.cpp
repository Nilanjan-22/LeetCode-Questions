class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt=0;
        for(int i=0;i<arr1.size();i++){
            bool Good=true;
            for(auto it: arr2){
                if(abs(arr1[i]-it)<=d){
                    Good=false;
                    break;
                }
            }
            if(Good)cnt++;
        }
        return cnt;
    }
};