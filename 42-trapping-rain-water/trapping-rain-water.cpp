class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        stack<int> st;
        vector<int> nge(n),pge(n);

        for(int i=n-1;i>=0;i--){
            while(!st.empty()&& height[st.top()]<=height[i]){
                st.pop();
            }
            if(st.empty())nge[i]=-1;
            else nge[i]=st.top();
            st.push(i);
        }

        st={};

        for(int i=0;i<n;i++){
            while(!st.empty() && height[st.top()]<=height[i]){
                st.pop();
            }
            if(st.empty())pge[i]=-1;
            else pge[i]=st.top();
            st.push(i);
        }

        int totalWater=0;
        unordered_map<int,int> alreadyConsidered;
        for(int i=0;i<n;i++){
            if(nge[i]==-1 || pge[i]==-1)continue;
            else {
                if(alreadyConsidered.find(height[i])!=alreadyConsidered.end() && alreadyConsidered[height[i]]>i)continue;
                int h=min(height[nge[i]],height[pge[i]])-height[i];
                int w=nge[i]-pge[i]-1;
                alreadyConsidered[height[i]]=nge[i];
                totalWater+=w*h;
            }
        }
        return totalWater;
        
    }
};