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

        queue<pair<TreeNode*,int>> nodes;
        nodes.push({root,0});
        vector<int> temp;
        int prevLevel=0;
        while(!nodes.empty()){
            TreeNode* cur=nodes.front().first;
            int level=nodes.front().second;
            nodes.pop();
            if(level!=prevLevel){
                if(prevLevel%2==1){
                    reverse(temp.begin(),temp.end());
                }
                traversal.push_back(temp);
                temp.clear();
                prevLevel=level;
            }
            temp.push_back(cur->val);
            
            if(cur->left!=NULL)nodes.push({cur->left,level+1});
            if(cur->right!=NULL)nodes.push({cur->right,level+1});
        }
        if(prevLevel%2==1)reverse(temp.begin(),temp.end());
        traversal.push_back(temp);
        
        return traversal;
    }
};