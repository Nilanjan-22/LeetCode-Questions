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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;  //val, node
        unordered_set<int> root;
        for(int i=0;i<descriptions.size();i++){
            if(nodes.find(descriptions[i][0])==nodes.end()){
                TreeNode* node = new TreeNode(descriptions[i][0]);
                nodes[descriptions[i][0]]=node;
                root.insert(descriptions[i][0]);
            }

            if(descriptions[i][2]==1){
                TreeNode* node = nodes[descriptions[i][0]];
                if(nodes.find(descriptions[i][1]) == nodes.end()){
                    TreeNode* left = new TreeNode(descriptions[i][1]);
                    nodes[descriptions[i][1]]=left;
                }
                node->left = nodes[descriptions[i][1]];
                if(root.find(descriptions[i][1])!=root.end())root.erase(descriptions[i][1]);
            }
            else{
                TreeNode* node = nodes[descriptions[i][0]];
                if(nodes.find(descriptions[i][1]) == nodes.end()){
                    TreeNode* rightt = new TreeNode(descriptions[i][1]);
                    nodes[descriptions[i][1]]=rightt;
                }
                node->right = nodes[descriptions[i][1]];
                if(root.find(descriptions[i][1])!=root.end())root.erase(descriptions[i][1]);
            }
        }
        return nodes[*root.begin()];

    }
};