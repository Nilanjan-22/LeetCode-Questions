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
    void io(vector<int>& inorder, TreeNode* root){
        if(!root)return;
        io(inorder,root->left);
        inorder.push_back(root->val);
        io(inorder,root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        io(inorder,root);

        int l=0,h=inorder.size()-1;
        while(l<h){
            if(inorder[l]+inorder[h]==k)return true;
            else if(inorder[l]+inorder[h]<k){
                l++;
            }
            else h--;
        }
        return false;
    }
};