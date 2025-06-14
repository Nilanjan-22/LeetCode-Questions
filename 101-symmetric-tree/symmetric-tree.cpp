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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;

        queue<TreeNode*>q;
        vector<int> a,b;
        if(root->left){
            q.push(root->left);
            a.push_back(root->left->val);
        }
        if(root->right){
            q.push(root->right);
            b.push_back(root->right->val);
        }
        while(!q.empty()){
            int s=q.size();
            if(s%2==1)return false;
            reverse(b.begin(),b.end());
            if(a!=b)return false;
            a.clear();
            b.clear();
            for(int i=0;i<s/2;i++){
               TreeNode* n=q.front();
               if(n->left){
                q.push(n->left);
                a.push_back(n->left->val);
               }
               else{
                a.push_back(-1000);
               }
               if(n->right){
                q.push(n->right);
                a.push_back(n->right->val);
               }
               else{
                a.push_back(-1000);
               }
               q.pop();
            }
            for(int i=s/2;i<s;i++){
               TreeNode* n=q.front();
               if(n->left){
                q.push(n->left);
                b.push_back(n->left->val);
               }
               else{
                b.push_back(-1000);
               }
               if(n->right){
                q.push(n->right);
                b.push_back(n->right->val);
               }
               else{
                b.push_back(-1000);
               }
               q.pop();
            }
        }
        return true;
    }
};