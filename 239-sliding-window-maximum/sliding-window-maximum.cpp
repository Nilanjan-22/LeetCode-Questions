class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans, nge(n),pge(n);

        stack<int> st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }

            if(st.empty())nge[i]=n;
            else nge[i]=st.top();

            st.push(i);
        }

        st={};

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }

            if(st.empty())pge[i]=-1;
            else pge[i]=st.top();

            st.push(i);
        }

        for(int i=0;i<n;i++){
            int r=min(k,i-pge[i]);
            int l=min(k,nge[i]-i);
            if(r+l-1<k)continue;
            int times=(r+l-1)%k;
            for(int it=0;it<=times;it++){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};