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
    stack<TreeNode*> st; 
    BSTIterator(TreeNode* root) {
        TreeNode* cur=root;
        while(cur){
            st.push(cur);
            cur=cur->left;
        }
    }
    
    int next() {
        int n=st.top()->val;
        TreeNode* cur=st.top()->right;
        st.pop();
        while(cur){
            st.push(cur);
            cur=cur->left;
        }
        return n;
    }
    
    bool hasNext() {
        if(st.empty())return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */