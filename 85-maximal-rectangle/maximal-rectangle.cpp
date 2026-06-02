class Solution {
public:
    int maxAreaOfBuildings(vector<int>& buildings){
        int n=buildings.size();
        vector<int> nse(n), pse(n);
        pse[0]=-1;
        nse[n-1]=n;
        stack<int> st;
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && buildings[st.top()]>=buildings[i])st.pop();
            if(st.empty())pse[i]=-1;
            else pse[i]=st.top();
            st.push(i);
        }
        st={};
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && buildings[st.top()]>=buildings[i])st.pop();
            if(st.empty())nse[i]=n;
            else nse[i]=st.top();
            st.push(i);
        }

        int maxArea=0;
        for(int i=0;i<n;i++){
            maxArea=max(maxArea, buildings[i]*(nse[i]-pse[i]-1));
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix[0].size();
        vector<int> buildings(n,0);
        int maxArea=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1')buildings[j]+=1;
                else buildings[j]=0;
            }
            maxArea=max(maxArea, maxAreaOfBuildings(buildings));
        }
        return maxArea;
    }
};