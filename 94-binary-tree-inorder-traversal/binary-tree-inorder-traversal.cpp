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
    void inTraversal(TreeNode* node, vector<int>& inOrder){
        if(node==NULL)return;
        inTraversal(node->left, inOrder);
        inOrder.push_back(node->val);
        inTraversal(node->right , inOrder);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrder;
        inTraversal(root, inOrder);
        return inOrder;
    }
};