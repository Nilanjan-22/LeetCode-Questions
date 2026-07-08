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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int stp, int enp, int sti, int eni){
        if(sti>eni)return NULL;

        TreeNode* node= new TreeNode(preorder[stp]);
        int ind=mp[preorder[stp]];
        int ll=ind-sti;
        int rl=eni-ind;
        node->left = build(preorder, inorder,stp+1 , stp+ll, sti, ind-1);
        node->right = build(preorder, inorder, stp+ll+1,enp, ind+1,eni);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }

        return build(preorder,inorder,0,n-1,0,n-1);
    }
};