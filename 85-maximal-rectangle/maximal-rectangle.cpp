class Solution {
public:
    // stack solution
    int largestRectangleArea(vector<int>& heights) {
        stack <int> st;
        int maxArea=0;
        int n = heights.size();
        for(int i=0; i<heights.size();i++){
            if(st.empty() || heights[st.top()]<=heights[i])st.push(i);
            else{
                int area;
                while(!st.empty() && heights[st.top()]>heights[i]){
                    int h = heights[st.top()];
                    st.pop();
                    int l;
                    if(st.empty())l=-1;
                    else l=st.top();

                    area = h*(i-l-1);
                    maxArea=max(area,maxArea);
                }
                st.push(i);
            }
        }
        while(!st.empty()){
            int h = heights[st.top()];
            st.pop();
            int l;
            if(!st.empty())l=st.top();
            else l=-1;
            maxArea = max(maxArea, h*(n-l-1));
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n1=matrix.size();
        int n2=matrix[0].size();
        vector<int> prefix(n2,0);
        int ans=0;
        for(int i=0; i<matrix.size();i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]=='0')prefix[j]=0;
                else prefix[j]++;
            }
            ans=max(ans,largestRectangleArea(prefix));
        }
        return ans;
    }
};