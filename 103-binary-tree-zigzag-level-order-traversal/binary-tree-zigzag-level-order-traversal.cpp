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
        vector<vector<int>> traversal;
        if(root==NULL)return traversal;
        queue<TreeNode*> q;
        q.push(root);
        int lvl=0;
        while(!q.empty()){
            int s=q.size();
            vector<int> temp;
            for(int i=0;i<s;i++){
                TreeNode* node=q.front();
                q.pop();
                temp.push_back(node->val);

                if(node->left!=NULL)q.push({node->left});
                if(node->right!=NULL)q.push({node->right});
            }
            if(lvl%2==1){
                reverse(temp.begin(),temp.end());
            }
            traversal.push_back(temp);
            lvl++;
        }
        return traversal;
    }
};