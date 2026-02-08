class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        long long ans=0;
        long long l=0,r=1;
        set<pair<int,int>> st;
        st.insert({nums[0],0});
        while(r<n){
            st.insert({nums[r],r});
            long long min=(*st.begin()).first;
            long long max=(*st.rbegin()).first;
            if((max-min)*(r-l+1)<=k)r++;
            else{
                st.erase({nums[l],l});
                long long s=r-l;
                ans+=s;
                l++;
            }
        }
        long long s=r-l;
        cout<<r<<" "<<l;
        ans+=(s*(s+1))/2;
        
        return ans;

    }
};