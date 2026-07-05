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
    void allPaths(TreeNode* root, string& s, vector<string>& ans){
        if(root->left==NULL && root->right==NULL){
            string t=s;
            s+=to_string(root->val);
            ans.push_back(s);
            s=t;
            return;
        }

        string t=s;
        s+=to_string(root->val);
        s+="->";

        if(root->left!=NULL){
            allPaths(root->left,s,ans);
        }
        if(root->right!=NULL){
            allPaths(root->right,s,ans);
        }
        s=t;
        return;

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s="";
        allPaths(root,s,ans);
        return ans;
    }
};