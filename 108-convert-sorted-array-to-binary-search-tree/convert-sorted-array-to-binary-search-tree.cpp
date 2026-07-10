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
    TreeNode* convert(int st, int en, vector<int>& nums){
        if(en<st)return NULL;
        int mid=(st+en)/2;

        TreeNode* node = new TreeNode (nums[mid]);
        node->left = convert(st,mid-1,nums);
        node->right=convert(mid+1,en,nums);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return convert(0,n-1,nums);
    }
};