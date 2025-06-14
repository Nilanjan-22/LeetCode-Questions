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
    void path(TreeNode* n, int v, vector<TreeNode*>& p,vector<TreeNode*>& ans){
        if(!n)return;
        p.push_back(n);

        if(n->val==v){
            ans=p;
            return;
        }
        path(n->left,v,p,ans);
        if(ans.size()>0)return;
        path(n->right,v,p,ans);
        if(ans.size()>0)return;
        p.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p1,q1,temp;
        path(root,p->val,temp,p1);
        temp.clear();
        path(root,q->val,temp,q1);
        
        int s1=p1.size(),s2=q1.size();
        int s=min(s1,s2);
        TreeNode* ans=root;
        for(int i=1;i<s;i++){
            if(p1[i]->val==q1[i]->val)ans=p1[i];
        }
        return ans;
    }
};