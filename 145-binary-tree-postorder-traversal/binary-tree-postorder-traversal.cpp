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
void postTraversal(TreeNode* node, vector<int>& postOrder){
        if(node==NULL)return;
        postTraversal(node->left, postOrder);
        postTraversal(node->right , postOrder);
        postOrder.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postOrder;
        postTraversal(root, postOrder);
        return postOrder;
    }
};