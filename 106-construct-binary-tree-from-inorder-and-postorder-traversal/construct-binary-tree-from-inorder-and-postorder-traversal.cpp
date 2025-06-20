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
    TreeNode* bt(vector<int>& io, int ios, int ioe, vector<int>& po, int pos, int poe, map<int,int>& hash){
        if(poe<pos || ioe<ios)return NULL;

        int data= po[poe];
        TreeNode* root = new TreeNode(data);

        int posi=hash[data];
        int rs=ioe-posi;

        root->right= bt(io,posi+1,ioe,po,poe-rs,poe-1,hash);
        root->left = bt(io,ios,posi-1,po,pos,poe-rs-1,hash);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> hash;
        int n=inorder.size();

        for(int i=0;i<n;i++){
            hash[inorder[i]]=i;
        }

        return bt(inorder,0,n-1,postorder,0,n-1,hash);
    }
};