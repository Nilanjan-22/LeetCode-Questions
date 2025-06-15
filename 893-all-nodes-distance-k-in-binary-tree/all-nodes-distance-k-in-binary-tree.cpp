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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root)return {};
        unordered_map<TreeNode*, TreeNode*> parent;
        vector<int> ans;
        //bfs traversal
        queue<TreeNode*>q;  //node
        int ini;

        q.push(root);
        
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* n=q.front();
                q.pop();
                if(n->left){
                    q.push(n->left);
                    parent[n->left]=n;
                }
                if(n->right){
                    q.push(n->right);
                    parent[n->right]=n;
                }
            }
        }

        unordered_map <TreeNode*,bool> vis;
        int lvl=0;
        q.push(target);
        vis[target]=true;
        while(!q.empty()){
            int s=q.size();
            if(lvl==k)break;
            for(int i=0;i<s;i++){
                TreeNode* n=q.front();
                q.pop();
                if(n->left && !vis[n->left]){
                    q.push(n->left);
                    vis[n->left]=true;
                }
                if(n->right && !vis[n->right]){
                    q.push(n->right);
                    vis[n->right]=true;
                }
                if(parent[n] && !vis[parent[n]]){
                    q.push(parent[n]);
                    vis[parent[n]]=true;
                }
            }
            lvl++;
        }

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};