class Solution {
public:
    int ans(vector<int>& heights){
        int n=heights.size();
        vector<int> nse(n),pse(n);
        stack<int> st={};

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i])st.pop();
            if(st.empty())pse[i]=-1;
            else pse[i]=st.top();
            st.push(i);
        }

        st={};
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i])st.pop();
            if(st.empty())nse[i]=n;
            else nse[i]=st.top();
            st.push(i);
        }

        int maxarea=0;
        for(int i=0;i<n;i++){
            maxarea=max(maxarea, (nse[i]-pse[i]-1)*heights[i]);
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> h(matrix[0].size(),0);
        int maxarea=-1;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='0')h[j]=0;
                else h[j]++;
            }
            maxarea=max(maxarea,ans(h));
        }
        return maxarea;
    }
};