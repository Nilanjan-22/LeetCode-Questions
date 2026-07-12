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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* cur=root;
        int ind=0;
        int results=-1;
        while(cur){
            if(cur->left==NULL){
                ind++;
                if(ind==k)results= cur->val;
                cur=cur->right;
            }
            else{
                TreeNode* next=cur->left;
                while(next->right!=NULL && next->right!=cur){
                    next=next->right;
                }
                if(next->right==NULL){
                    next->right=cur;
                    cur=cur->left;
                }
                else{
                    next->right=NULL;
                    ind++;
                    if(ind==k)results= cur->val;
                    cur=cur->right;
                }
            }
        }
        return results;
    }
};