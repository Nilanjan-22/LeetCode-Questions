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
    TreeNode* build(vector<int>& po, int& i, int ub){
        if(i==po.size() || ub<=po[i])return NULL;
        TreeNode* root= new TreeNode(po[i]);
        i++;
        root->left=build(po,i,root->val);
        root->right=build(po,i,ub);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        int ub=INT_MAX;
        return build(preorder,i,ub);
    }
};