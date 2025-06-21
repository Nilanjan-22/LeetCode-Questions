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
    void pt(TreeNode* n, vector<int>& p){
        if(n==NULL)return;
        p.push_back(n->val);
        pt(n->left,p);
        pt(n->right,p);
    }
    void flatten(TreeNode* root) {
        vector<int> preorder;
        pt(root,preorder);
        // TreeNode* cur=root;

        for(int i=1;i<preorder.size();i++){
            root->left=NULL;
            root->right=new TreeNode(preorder[i]);
            root=root->right;
        }
    }
};