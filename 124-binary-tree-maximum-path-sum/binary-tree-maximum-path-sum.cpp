/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum(TreeNode* root, int& maxVal){
        if(root==NULL)return -1e9;
        
        int left = maxSum(root->left, maxVal);
        int right= maxSum(root->right, maxVal);
        
        int takeAll=left+right+root->val;
        int takeOneSide=root->val + max(0,max(left,right));
        
        int total=max(takeAll, takeOneSide);

        maxVal=max(maxVal,total);
        return max(0,max(left,right))+root->val;

    }
    int maxPathSum(TreeNode* root) {
        int maxVal=-1e9;
        maxSum(root,maxVal);
        return maxVal;
    }
};