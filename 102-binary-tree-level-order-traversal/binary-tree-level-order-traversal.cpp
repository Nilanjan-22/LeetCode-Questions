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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        queue<TreeNode*> q;
        if(root==NULL)return ans;
        q.push(root);

        while(!q.empty()){
            vector<int> lvl;
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* node = q.front();
                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(node->right);
                lvl.push_back(node->val);
                q.pop();
            }
            ans.push_back(lvl);
        }
        return ans;
    }
};