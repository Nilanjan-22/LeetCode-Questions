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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int zig =1;
        // if zig=0 left to right else right to left
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        stack<TreeNode*> st;
        vector<int> lvl;
        if(root==NULL)return ans;
        q.push(root);
        while(!q.empty()){
            if(zig==0){
                int s=q.size();
                for(int i=0;i<s;i++){
                    TreeNode* n=q.front();
                    if(n->left!=NULL)q.push(n->left);
                    if(n->right!=NULL)q.push(n->right);
                    lvl.push_back(st.top()->val);
                    st.pop();
                    q.pop();
                }
                zig=1;
                ans.push_back(lvl);
                lvl.clear();
            }
            else{
                int s=q.size();
                for(int i=0;i<s;i++){
                    TreeNode* n=q.front();
                    if(n->left!=NULL){
                        q.push(n->left);
                        st.push(n->left);
                    }
                    if(n->right!=NULL){
                        q.push(n->right);
                        st.push(n->right);
                    }
                    lvl.push_back(n->val);
                    q.pop();
                }
                zig=0;
                ans.push_back(lvl);
                lvl.clear();
            }
        }
        return ans;
    }
};