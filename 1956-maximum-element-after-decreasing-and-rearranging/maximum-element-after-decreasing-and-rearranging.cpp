class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int prev=0;
        for(int i=0;i<n;i++){
            if(arr[i]>prev){
                prev++;
            }
        }
        return prev;
    }
};