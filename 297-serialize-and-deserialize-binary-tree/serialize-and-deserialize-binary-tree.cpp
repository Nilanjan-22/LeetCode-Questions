/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serialized;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node==NULL){
                serialized+="null";
                serialized.push_back(',');
                continue;
            }
            else {
                serialized+=to_string(node->val);
                serialized.push_back(',');
            }
            q.push(node->left);
            q.push(node->right);
        }
        serialized.pop_back();
        return serialized;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string s;
        char delimiter = ',';
        getline(ss,s,delimiter);
        
        TreeNode* root= NULL;
        if(s=="null")return root;
        else root = new TreeNode (stoi(s));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            getline(ss,s,delimiter);
            if(s!="null"){
                node->left = new TreeNode (stoi(s));
                q.push(node->left);
            }
            getline(ss,s,delimiter);
            if(s!="null"){
                node->right = new TreeNode (stoi(s));
                q.push(node->right);
            }
        }
        
        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));