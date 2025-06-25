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
    TreeNode* createTree(vector<int>& po, int pos, int poe, vector<int>& io, int ios, int ioe, map<int,int>& hash){
        if(ioe<ios || poe<pos)return NULL;
        int data=po[pos];
        TreeNode* root= new TreeNode(data);

        int pos_io=hash[data];
        int ls=pos_io-ios;

        root->left= createTree(po,pos+1,pos+ls,io,ios,pos_io-1,hash);
        root->right= createTree(po,pos+ls+1,poe,io,pos_io+1,ioe,hash);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        vector<int> inorder(n);

        for(int i=0;i<n;i++){
            inorder[i]=preorder[i];
        }

        sort(inorder.begin(),inorder.end());

        map<int,int> hash;
        for(int i=0;i<n;i++)hash[inorder[i]]=i;
        return createTree(preorder,0,n-1,inorder,0,n-1,hash);

    }
};