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
    TreeNode* deleteNode(TreeNode* root, int key) {
        //find the node to be deleted
        //and store its left and right
        if(!root)return NULL;
        TreeNode* cur=root;
        TreeNode* l;
        TreeNode* r;
        TreeNode* parent;
        if(cur->val==key){
            l=cur->left;
            r=cur->right;

            cur->left=cur->right=NULL;
            if(!r)return l;
            parent=r;
            while(r->left!=NULL)r=r->left;
            r->left=l;
            return parent;
        }
        while(cur){
            if(cur->left && cur->left->val==key){
                parent=cur;
                cur=cur->left;

                l=cur->left;
                r=cur->right;
                if(!r){
                    parent->left=l;
                    return root;
                }
                parent->left=r;
                cur->left=cur->right=NULL;
                while(r->left!=NULL)r=r->left;
                r->left=l;
                return root;
            }
            else if(cur->right && cur->right->val==key){
                parent=cur;
                cur=cur->right;

                l=cur->left;
                r=cur->right;
                if(!r){
                    parent->right=l;
                    return root;
                }
                parent->right=r;
                cur->left=cur->right=NULL;
                while(r->left!=NULL)r=r->left;
                r->left=l;
                return root;
            }
            else if(cur->val>key)cur=cur->left;
            else cur=cur->right;
        }
        return root;
    }
};