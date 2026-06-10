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
    vector<int> rightSideView(TreeNode* root) {
    if(root==NULL)return {};
    queue<pair<TreeNode*, int>> q;
    map<int,int> lastOfEachLeveL;
    
    q.push({root,0});

    while(!q.empty()){
        int lvl=q.front().second;
        TreeNode* node=q.front().first;

        q.pop();

        lastOfEachLeveL[lvl]=node->val;

        if(node->left!=NULL)q.push({node->left,lvl+1});
        if(node->right!=NULL)q.push({node->right,lvl+1});
    }

    vector<int> ans;
    for(auto& it: lastOfEachLeveL){
        ans.push_back(it.second);
    }

    return ans;
    }
};