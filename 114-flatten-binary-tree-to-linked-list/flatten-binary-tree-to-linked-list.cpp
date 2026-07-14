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
    void flatten(TreeNode* root) {
        if(root!=NULL && root->left){
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            TreeNode* temp=left;
            while(temp->right)temp=temp->right;
            temp->right=right;
            root->right=left;
            root->left=NULL;
        }
        if(root!=NULL)flatten(root->right);
    }
};