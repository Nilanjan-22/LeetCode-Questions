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
    //iterative approach using 1 stack (kinda Hard)
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* cur=root;
        vector<int> ans;
        if(root==NULL) return ans;

        stack<TreeNode*> st;

        while(cur!=NULL || !st.empty()){
            if(cur!=NULL){
                st.push(cur);
                cur=cur->left;
            }
            else{
                TreeNode* temp=st.top()->right;
                if(temp!=NULL){
                    cur=temp;
                }
                else{
                    temp=st.top();
                    ans.push_back(temp->val);
                    st.pop();
                    while(!st.empty() && temp==st.top()->right){
                        temp=st.top();
                        ans.push_back(temp->val);
                        st.pop();
                    }
                }
            }
        }
        return ans;
    }
};