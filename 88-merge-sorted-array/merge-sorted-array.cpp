class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0)return ;
        int i=0,j=0;
        while(i<m){
            if(nums1[i]>nums2[j]){
                swap(nums1[i],nums2[j]);
                int t=j;
                while(t<n-1 && nums2[t]>nums2[t+1]){
                    swap(nums2[t],nums2[t+1]);
                    t++;
                }
            }
            i++;
        }
        for(;i<m+n;i++){
            nums1[i]=nums2[j];
            j++;
        }
    }
};