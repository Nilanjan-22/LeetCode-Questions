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
    int height(TreeNode* node){
        if(!node)return 0;
        int lh=0,rh=0;
        TreeNode* it=node;
        while(it){
            lh++;
            it=it->left;
        }
        it=node;
        while(it){
            rh++;
            it=it->right;
        }
        if(lh==rh)return pow(2,lh)-1;

        return 1+ height(node->left)+height(node->right);
    }
    int countNodes(TreeNode* root) {
        return height(root);
    }
};