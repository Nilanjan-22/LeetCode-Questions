/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //just check where it is splitting, if there is no point of split that is the lca
        //else the point of splitting is the lca

        TreeNode* cur=root;
        int minV=min(p->val,q->val);
        int maxV=max(p->val,q->val);
        while(cur){
            if(minV<cur->val && maxV>cur->val)return cur;
            else if(minV>cur->val)cur=cur->right;
            else if(maxV<cur->val)cur=cur->left;
            else return cur;
        }
        return cur;
    }
};