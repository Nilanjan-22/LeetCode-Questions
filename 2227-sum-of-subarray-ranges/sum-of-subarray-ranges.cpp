class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int> nge(n);
        vector<int>pge(n);
        vector<int>nse(n);
        vector<int>pse(n);

        stack<int> st;

        //forming nge
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(st.empty())nge[i]=n;
            else nge[i]=st.top();

            st.push(i);
        }
        st={};

        //forming nse
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty())nse[i]=n;
            else nse[i]=st.top();

            st.push(i);
        }
        st={};

        //forming pge
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            if(st.empty())pge[i]=-1;
            else pge[i]=st.top();

            st.push(i);
        }

        st={};

        //forming pse
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            if(st.empty())pse[i]=-1;
            else pse[i]=st.top();

            st.push(i);
        }

        long long ans=0;
        for(int i=0;i<n;i++){
            long long sum = (long long)nums[i]*((long long)i-(long long)pge[i])*((long long)nge[i]-(long long)i);
            long long minus=(long long)nums[i]*((long long)i-(long long)pse[i])*((long long)nse[i]-(long long)i);

            ans+=(sum-minus);
        }

        return ans;
    }
};