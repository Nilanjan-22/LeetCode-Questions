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
    pair<int,bool> recursion(TreeNode* root){
        if(root==NULL)return {0,true};
        pair<int,bool> l=recursion(root->left);
        pair<int,bool> r=recursion(root->right);
        if(l.second==false || r.second==false)return {-1,false};
        if(abs(l.first-r.first)<=1)return {max(l.first+1,r.first+1),true};
        else return {-1,false};
    }
    bool isBalanced(TreeNode* root) {
        pair<int,bool> ans=recursion(root);
        return ans.second;
    }
};