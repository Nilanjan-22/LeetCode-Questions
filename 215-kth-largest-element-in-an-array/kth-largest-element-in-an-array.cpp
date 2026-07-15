class Solution {
public:
    int solve(int l, int r, vector<int>& temp, int k){
        if(l==r)return temp[l];

        int pivot= temp[l];
        int i=l,j=r;
        while(i<=j){
            if(temp[i]<pivot && temp[j]>pivot){
                swap(temp[i],temp[j]);
                i++;
                j--;
            }
            if(i<=j && temp[i]>=pivot)i++;
            if(i<=j && temp[j]<=pivot)j--;
        }
        swap(temp[l],temp[j]);
        if(j==k-1)return pivot;
        
        if(j<k-1)return solve(j+1,r,temp,k);
        return solve(l,j-1,temp,k);

    }
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> temp;
        temp=nums;
        int n=nums.size();
        return solve(0,n-1,temp,k);
    }
};