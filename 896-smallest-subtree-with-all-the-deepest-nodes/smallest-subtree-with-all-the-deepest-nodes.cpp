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
    map<TreeNode* , pair<int,TreeNode*>> mp;
    int maxd=INT_MIN;
    void dfs(int dist, TreeNode* parent, TreeNode* node){
        if(node==NULL)return;
        maxd=max(dist,maxd);
        dfs(dist+1,node,node->left);
        mp[node]={dist,parent};
        dfs(dist+1,node,node->right);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(0,NULL,root);
        set<TreeNode*> temp;
        for(auto it:mp){
            if(it.second.first==maxd)temp.insert(it.first);
        }
        while(temp.size()>1){
            set<TreeNode*> temp2;
            for(auto it: temp){
                temp2.insert(mp[it].second);
            }
            temp=temp2;
        } 
        return *temp.begin();    
    }
};