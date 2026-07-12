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

    int kthSmallest(TreeNode* root, int k) {
        int ind=0;
        stack<TreeNode*> st;
        TreeNode* cur=root;
        set<TreeNode*> vis;
        while(ind<k){
            while(cur->left!=NULL && vis.find(cur)==vis.end()){
                st.push(cur);
                vis.insert(cur);
                cur=cur->left;
            }
            ind++;
            if(ind==k)return cur->val;
            if(cur->right!=NULL)cur=cur->right;
            else{
                cur=st.top();
                st.pop();
            }
        }
        return -1;
    }
};