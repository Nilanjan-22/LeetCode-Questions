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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;  //every col is shifted by thousand
        if(root==NULL)return ans;
        map<int,vector<int>> mp;
        queue<pair<TreeNode*,int>> q; //node and col

        q.push({root,0});
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* n=q.front().first;
                int col = q.front().second;

                if(n->left){
                    q.push({n->left,col-1});
                }
                if(n->right){
                    q.push({n->right,col+1});
                }
                q.pop();
                pq.push({n->val,col});
            }
            while(!pq.empty()){
                int c=pq.top().second;
                int v=pq.top().first;
                pq.pop();
                if(mp.find(c)==mp.end()){
                    vector<int> f;
                    f.push_back(v);
                    mp[c]=f;
                }
                else mp[c].push_back(v);
            }
        }
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};