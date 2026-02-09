class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> st;
        for(int i=0;i<nums.size();i++){
            if(st.empty() || st.top()!=nums[i]){
                st.push(nums[i]);
            }
            else{
                long long t=nums[i];
                while(!st.empty() && t==st.top()){
                    t=2LL*st.top();
                    st.pop();
                }
                st.push(t);
            }
        }
        int s=st.size();
        vector<long long> ans(s);
        int i=s-1;
        while(!st.empty()){
            ans[i]=st.top();
            st.pop();
            i--;
        }
        return ans;
    }
};