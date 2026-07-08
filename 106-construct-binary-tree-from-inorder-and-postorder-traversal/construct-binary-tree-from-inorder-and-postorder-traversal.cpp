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
    map<int,int> mp;
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,int stp, int enp, int sti, int eni){
        if(eni<sti)return NULL;

        TreeNode* node=new TreeNode(postorder[stp]);
        int ind=mp[postorder[stp]];
        int ll=ind-sti;
        int rl=eni-ind;

        node->right = build(inorder, postorder, stp+1,stp+rl,ind+1,eni);
        node->left= build(inorder, postorder,stp+rl+1,enp,sti,ind-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        reverse(postorder.begin(), postorder.end());
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return build(inorder,postorder,0,n-1,0,n-1);
    }
};