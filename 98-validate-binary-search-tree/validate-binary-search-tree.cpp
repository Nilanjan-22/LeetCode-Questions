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
    bool isValidBST(TreeNode* root) {
        bool ans=true;

        long long prev_val=-2147483649;
        TreeNode* cur=root;

        while(cur){
            if(cur->left==NULL){
                if((long long)prev_val>=(long long)cur->val)ans=false;
                prev_val=cur->val;

                cur=cur->right;
            }
            else{
                TreeNode* prev=cur->left;

                while(prev->right&& prev->right!=cur){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=cur;
                    cur=cur->left;
                }
                else{
                    prev->right=NULL;
                    if(prev_val>=cur->val)ans=false;
                    prev_val=cur->val;
                    cur=cur->right;
                }
            }
        }
        return ans;
    }
};