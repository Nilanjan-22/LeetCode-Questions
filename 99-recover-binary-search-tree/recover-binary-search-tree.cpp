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
    void recoverTree(TreeNode* root) {

        TreeNode* cur=root;
        TreeNode* prev=NULL;
        TreeNode* r1=NULL;
        TreeNode* r2=NULL;
        while(cur){
            if(!cur->left){
                if(prev&&prev->val>cur->val){
                   if(!r1){
                    r1=prev;
                   }
                   r2=cur;
                }
                prev=cur;
                cur=cur->right;
            }
            else{
                TreeNode* temp=cur->left;
                while(temp->right!=NULL && temp->right!=cur){
                    temp=temp->right;
                }

                if(temp->right==NULL){
                    temp->right=cur;
                    cur=cur->left;
                }
                else{
                    temp->right=NULL;
                    if(prev && prev->val>cur->val){
                       if(!r1){
                        r1=prev;
                       }
                       r2=cur;
                    }
                    prev=cur;
                    cur=cur->right;
                }
            }
        }
        int t=r1->val;
        r1->val=r2->val;
        r2->val=t;

    }
};