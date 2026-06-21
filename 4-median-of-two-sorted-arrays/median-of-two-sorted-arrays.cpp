class Solution {
public:
    bool canBe(int num,int posNeed, vector<int>& nums1, vector<int>& nums2){
        int pos=upper_bound(nums1.begin(),nums1.end(),num)-nums1.begin();
        pos+=upper_bound(nums2.begin(),nums2.end(),num)-nums2.begin();
        if(pos>posNeed)return true;
        return false;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();

        if(n==0 || m==0){
            if(n==0){
                if(m%2==0){
                    double n1=nums2[m/2], n2=nums2[m/2 -1];
                    return (n1+n2)/2;
                }
                else{
                    return (double)nums2[m/2];
                }
            }
            else{
                if(n%2==0){
                    double n1=nums1[n/2], n2=nums1[n/2 -1];
                    return (n1+n2)/2;
                }
                else{
                    return (double)nums1[n/2];
                }
            }
        }
        int low=min(nums1[0],nums2[0]), high=max(nums1[n-1],nums2[m-1]);

        int n1=-1,n2=-1;
        int medianIdx=(m+n)/2;
        while(low<=high){
            int mid=(low+high)/2;
            if(canBe(mid,medianIdx,nums1,nums2)){
                n1=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        
        if((n+m)%2==0){
            medianIdx=(m+n)/2 -1;
            low=min(nums1[0],nums2[0]), high=max(nums1[n-1],nums2[m-1]);
            while(low<=high){
                int mid=(low+high)/2;
                if(canBe(mid,medianIdx,nums1,nums2)){
                    n2=mid;
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            return ((double)n1+(double)n2)/2;
        }
        return (double)n1;


    }
};