class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int belowPivot=0, cntPivot=0 , n=nums.size();
        vector<int> finalArray(n,pivot);
        for(int i=0;i<n;i++){
            if(nums[i]<pivot)belowPivot++;
            else if(nums[i]==pivot)cntPivot++;
        }
        int st=0,afterPivot=belowPivot+cntPivot;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                finalArray[st]=nums[i];
                st++;
            }
            else if(nums[i]>pivot){
                finalArray[afterPivot]=nums[i];
                afterPivot++;
            }
        }

        return finalArray;

    }
};