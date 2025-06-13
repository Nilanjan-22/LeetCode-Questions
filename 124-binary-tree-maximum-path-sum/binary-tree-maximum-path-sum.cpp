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
    int pathsum(TreeNode* node,int& s){
        if(node==NULL)return 0;
        int ls =max(0,pathsum(node->left,s));
        int rs =max(0,pathsum(node->right,s));
        int sum=ls+rs+node->val;
        s=max(sum,s);
        return max(ls,rs)+node->val;
    }
    int maxPathSum(TreeNode* root) {
        int s=INT_MIN;
        pathsum(root,s);
        return s;
    }
};