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
class BSTIterator {
public:
    vector<int> inorder;
    int i=0;
    void io(TreeNode* root){
        if(!root)return;
        io(root->left);
        inorder.push_back(root->val);
        io(root->right);
    }
    BSTIterator(TreeNode* root) {
        io(root);
    }
    
    int next() {
        if(i>inorder.size())return NULL;
        return inorder[i++];
    }
    
    bool hasNext() {
        if(i<inorder.size())return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */