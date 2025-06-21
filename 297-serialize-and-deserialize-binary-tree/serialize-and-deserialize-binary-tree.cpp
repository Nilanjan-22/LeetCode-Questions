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
        //just use basic level order traversal

        string s="";
        if(!root)return s;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* n=q.front();
            q.pop();
            if(n==NULL)s.append("n,");
            else{
                s.append(to_string(n->val)+',');
                q.push(n->left);
                q.push(n->right);
            }
        }
    
        cout<<s;
        return s;
    }

    TreeNode* deserialize(string data) {
        //for every number in the strings take the next two
        int si=data.size();
        if(si==0)return NULL;
    
        stringstream s(data);
        string str;
        getline(s,str,',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* n=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="n")n->left=NULL;
            else{
                n->left= new TreeNode(stoi(str));
                q.push(n->left);
            }

            getline(s,str,',');
            if(str=="n")n->right=NULL;
            else{
                n->right=new TreeNode(stoi(str));
                q.push(n->right);
            }
        }
        return root;

    }
};


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
