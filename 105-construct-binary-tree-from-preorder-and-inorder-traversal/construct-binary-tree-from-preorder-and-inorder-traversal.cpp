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
    TreeNode* bt(vector<int>& po, int pos, int poe, vector<int>& io, int ios, int ioe, map<int,int>& hash){
        if(poe<pos || ioe<ios)return NULL;

        int data=po[pos];
        TreeNode* root = new TreeNode(data);     

        int posi=hash[data];
        int ls=posi-ios;

        root->left = bt(po,pos+1,pos+ls,io,ios,posi-1,hash);
        root->right = bt(po,pos+ls+1,poe, io,posi+1,poe,hash);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> hash;
        int n= inorder.size();
        for(int i=0;i<n;i++){
            hash[inorder[i]]=i;
        }
        return bt(preorder,0,n-1,inorder,0,n-1,hash);
    }
};