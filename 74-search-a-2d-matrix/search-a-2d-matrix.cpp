class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        int low=0, high=n-1;
        int row=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(matrix[mid][m-1]>=target){
                row=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        cout<<row;
        if(row==-1)return false;
        low=0,high=m-1;
        int col=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(matrix[row][mid]>=target){
                col=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        if(col==-1)return false;
        if(matrix[row][col]==target)return true;
        return false;
    }
};