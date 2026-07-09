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
    bool check(TreeNode* half1, TreeNode* half2){
        if(half1==NULL && half2==NULL)return true;
        else if(half1==NULL || half2==NULL)return false;
        bool leftHalf=check(half1->left, half2->right);
        bool rightHalf= check(half1->right, half2->left);
        if(leftHalf && rightHalf && half1->val==half2->val)return true;
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return check(root,root);
    }
};