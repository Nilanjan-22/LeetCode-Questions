class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n=nums.size();
        vector<int> arr(value,0);

        for(int i=0;i<n;i++){
            if(nums[i]<0){
                int rem=value-(-nums[i])%value;
                arr[rem%value]++;
            }
            else {
                arr[nums[i]%value]++;
            }
        }
        int minicnt=INT_MAX, rem=-1;
        for(int i=0;i<value;i++){
            if(arr[i]<minicnt){
                minicnt=arr[i];
                rem=i;
            }
        }
        return minicnt*value + rem;

        
    }
};