class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int> freq1(8e4+1, 0), freq2(8e4+1);
        for(int i=0;i<n;i++){
            freq1[nums1[i]]++;
            freq2[nums2[i]]++;
        }
        int cost=0; 
        for(int i=0; i<freq1.size();i++){
            if((freq1[i]+freq2[i])%2==1)return -1;
            cost += (abs(freq1[i]-freq2[i]))/2;
        }
        return cost/2;
    }
};