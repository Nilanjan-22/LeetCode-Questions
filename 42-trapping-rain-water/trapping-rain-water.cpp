class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int trappedWater = 0;
        vector<int> towers(n);
        int maxHeight=0;
        for(int i=0;i<n;i++){
            towers[i]=maxHeight;
            maxHeight = max(maxHeight,height[i]);
        }
        maxHeight=0;
        for(int i=n-1;i>=0;i--){
            towers[i]=min(maxHeight,towers[i]);
            trappedWater += max(0,towers[i]-height[i]);
            maxHeight = max(maxHeight,height[i]);
        }

        return trappedWater;

    }
};