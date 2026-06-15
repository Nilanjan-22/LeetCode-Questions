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
    map<int,int> mp;
    TreeNode* build (vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd){
        if(preEnd<preStart || inEnd<inStart)return NULL;
        if(preEnd==preStart){
            TreeNode* root= new TreeNode(preorder[preEnd]);
            return root;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        int pos=mp[preorder[preStart]];
        int leftElements=pos-inStart;
        int rightElements = inEnd-pos;
        root->left= build(preorder,inorder,preStart+1,preStart+leftElements,inStart,pos-1);
        root->right=build(preorder,inorder,preStart+leftElements+1,preEnd,pos+1,inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return build(preorder,inorder,0,n-1,0,n-1);
    }
};