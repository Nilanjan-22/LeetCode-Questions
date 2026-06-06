class Solution {
public:
    int cntReversePairs(int st,int mid, int en, vector<int>& nums){
        int ptr1=st, ptr2=mid+1;
        int cnt=0;
        int l=st,r=mid+1;
        for(int i=st;i<mid+1;i++){
            while(r<=en && (long long)nums[i]>2LL*(long long)nums[r])r++;
            cnt+=r-mid-1;
        }
        vector<int> temp;
        while(ptr1<mid+1 && ptr2<=en){
            if(nums[ptr1]<=nums[ptr2]){
                temp.push_back(nums[ptr1]);
                ptr1++;
            }
            else {
                temp.push_back(nums[ptr2]);
                ptr2++;
            }
        }
        while(ptr1<mid+1){
            temp.push_back(nums[ptr1]);
            ptr1++;
        }
        while(ptr2<=en){
            temp.push_back(nums[ptr2]);
            ptr2++;
        }

        for(int i=st;i<=en;i++){
            nums[i]=temp[i-st];
        }
        return cnt;
    }
    int solve(int st, int en, vector<int>& nums){
        if(st>=en) return 0;
        int mid=(st+en)/2;
        int rp = solve(st,mid,nums) + solve(mid+1,en,nums);
        rp+=cntReversePairs(st,mid,en,nums);
        return rp;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return solve(0,n-1,nums);
    }
};