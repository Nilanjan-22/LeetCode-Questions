class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int rightPointer=0, leftPointer=n-1;
        while(rightPointer<n && colors[n-1]==colors[rightPointer]){
            rightPointer++;
        }
        while(leftPointer>=0 && colors[leftPointer]==colors[0]){
            leftPointer--;
        }

        int dist1=leftPointer;
        int dist2=n-1-rightPointer;
        return max(dist1,dist2);
    }
};