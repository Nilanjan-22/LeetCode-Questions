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
    TreeNode* lca(TreeNode* root, TreeNode* node1, TreeNode* node2){
        if(root==NULL || root==node1 || root==node2)return root;

        TreeNode* left=lca(root->left,node1,node2);
        TreeNode* right=lca(root->right,node1,node2);

        if(!left)return right;
        else if(!right)return left;
        else return root;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,int> nodeLvl; //stores level of each node

        queue<pair<TreeNode*,int>> q;
        q.push({root,0});

        while(!q.empty()){
            TreeNode* node=q.front().first;
            int lvl=q.front().second;
            nodeLvl[node]=lvl;
            q.pop();

            if(node->left!=NULL)q.push({node->left,lvl+1});
            if(node->right!=NULL)q.push({node->right,lvl+1});

        }
        
        vector<int> nodesAtKDistance;
        for(auto it: nodeLvl){
            TreeNode* node2=it.first;
            TreeNode* ancestor = lca(root,target,node2);
            int distance = nodeLvl[target]+nodeLvl[node2]-2*nodeLvl[ancestor];
            if(distance==k){
                nodesAtKDistance.push_back(node2->val);
            }
        }

        return nodesAtKDistance;
    }
};