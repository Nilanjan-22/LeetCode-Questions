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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* ceil=new TreeNode(1e8+1);
        TreeNode* cur=root;
        while(cur){
            if(cur->val>val){
                ceil=cur;
                cur=cur->left;
            }
            else{
                cur=cur->right;
            }
        }

        //insert this new node in the left of the ceil
        if(ceil->val==1e8+1){
            TreeNode* insert = new TreeNode(val);
            insert->left=root;
            return insert;
        }
        else{
            TreeNode* left=ceil->left;
            TreeNode* insert= new TreeNode(val);

            ceil->left=insert;
            insert->left=left;

            return root;
        }
        
    }
};