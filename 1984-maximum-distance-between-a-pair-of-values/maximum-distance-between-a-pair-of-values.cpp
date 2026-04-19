class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        int n=nums2.size(),m=nums1.size();
        int ans=0;
        while(i<m && j<n){
            if(nums2[j]>=nums1[i]){
                ans=max(ans,j-i);
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};