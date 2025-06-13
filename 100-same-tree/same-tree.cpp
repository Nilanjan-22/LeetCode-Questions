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
    // do bfs traversal of both together if mismatch return false
    bool bfs(TreeNode* node1, TreeNode* node2){
        queue<TreeNode*> q1,q2;
        if(node1==NULL && node2==NULL)return true;
        if(node1==NULL || node2==NULL || node1->val !=node2->val)return false;
        q1.push(node1);
        q2.push(node2);
        while(!q1.empty()){
            int s=q1.size();
            for(int i=0;i<s;i++){
                TreeNode* n1=q1.front();
                TreeNode* n2=q2.front();
                if((n1->left==NULL && n2->left!=NULL)  || (n2->left==NULL && n1->left!=NULL))return false;
                if((n1->right==NULL && n2->right!=NULL)  || (n2->right==NULL && n1->right!=NULL))return false;
                if(n1->left==NULL && n2->left==NULL && n1->right==NULL && n2->right==NULL){
                    q1.pop();
                    q2.pop();
                    continue;
                };
                if((n1->left!=NULL && n2->left!=NULL && n1->left->val != n2->left->val) || (n1->right!=NULL && n2->right!=NULL && n1->right->val !=n2->right->val))return false;

                if(n1->left !=NULL){
                    q1.push(n1->left);
                    q2.push(n2->left);
                }
                if(n1->right !=NULL){
                    q1.push(n1->right);
                    q2.push(n2->right);
                }
                q1.pop();
                q2.pop();
            }
        }
        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return bfs(p,q);
    }
};