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
    //iterative approach of doing all i.e preorder,postorder and inorder in one go
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> pre,in,post;
        stack<pair<TreeNode*,int>> st;
        if(root==NULL)return post;
        st.push({root,1});
        while(!st.empty()){
            int num=st.top().second;
            TreeNode* node=st.top().first;

            if(num==1){
                pre.push_back(node->val);
                st.pop();
                st.push({node,2});
                if(node->left!=NULL){
                    st.push({node->left,1});
                }
            }

            else if(num==2){
                in.push_back(node->val);
                st.pop();
                st.push({node,3});
                if(node->right!=NULL){
                    st.push({node->right,1});
                }
            }

            else{
                post.push_back(node->val);
                st.pop();
            }
        }

        return post;
    }
};