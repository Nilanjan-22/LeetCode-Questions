class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        // map<int, pair<int,int>> mp;
        // int cnt=0,ans=0;
        // mp[0]={-1,-1};
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]%2==0)cnt++;
        //     else cnt--;

        //     if(mp.find(cnt)!=mp.end()){
        //         mp[cnt].second=i;
        //         ans=max(ans,i-mp[cnt].first);
        //     }
        //     else{
        //         mp[cnt]={i,i};
        //     }

        // }
        // return ans;
        set<int> st;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int cnt=0;
            for(int j=i;j<nums.size();j++){
                if(st.find(nums[j])==st.end()){
                    st.insert(nums[j]);
                    if(nums[j]%2==0)cnt++;
                    else cnt--;
                    if(cnt==0)ans=max(ans,j-i+1);
                }
                if(cnt==0)ans=max(ans,j-i+1);
            }
            st.clear();
        }
        return ans;
    }
};