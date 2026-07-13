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
    void inorderTraversal(TreeNode* root, vector<int>& inorder){
        if(root->left!=NULL)inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        if(root->right!=NULL)inorderTraversal(root->right, inorder);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        inorderTraversal(root,inorder);
        int n=inorder.size();
        int i=0,j=n-1;
        while(i<j){
            if(inorder[i]+inorder[j] == k)return true;
            if(inorder[i]+inorder[j] < k)i++;
            else j--;
        }
        return false;
    }
};