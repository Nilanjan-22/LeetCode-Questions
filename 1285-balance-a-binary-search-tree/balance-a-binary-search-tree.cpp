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
    vector<int> vec;
    void inorder(TreeNode* root){
        if(root->left!=NULL)inorder(root->left);
        vec.push_back(root->val);
        if(root->right!=NULL)inorder(root->right);
    }
    void createTree(TreeNode* root, int l, int r){
        
        root->val=vec[(l+r)/2];
        int mid=(l+r)/2;
        if(l<=mid-1){
            TreeNode* le= new TreeNode();
            root->left=le;
            createTree(le,l,mid-1);
        }
        if(mid+1<=r){
            TreeNode* ri= new TreeNode();
            root->right=ri;
            createTree(ri,mid+1,r);
        }
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        for(int i=0;i<vec.size();i++){
            cout<<vec[i]<<" ";
        }
        int n=vec.size();
        TreeNode* ans= new TreeNode();
        createTree(ans,0,n-1);

        return ans;
    }
};