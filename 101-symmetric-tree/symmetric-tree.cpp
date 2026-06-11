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
    bool checkPalindrome(vector<pair<int,int>> & temp){
        int n=temp.size();
        if(n<1)return true;
        if(n%2==1)return false;

        int i=0,j=n-1;
        while(i<j){
            if(temp[i].first!=temp[j].first || temp[i].second!=-temp[j].second)return false;
            i++;
            j--;
        }
        return true;
        
    }
    bool isSymmetric(TreeNode* root) {
        vector<pair<int,int>> temp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        map<TreeNode*,int> lvl;
        lvl[root]=0;
        int prevLvl=0;
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int hlvl=q.front().second;
            int curlvl=lvl[node];
            q.pop();
            if(curlvl!=prevLvl){
                if(!checkPalindrome(temp))return false;
                temp.clear();
                prevLvl=curlvl;
            }
            if(node!=root)temp.push_back({node->val,hlvl});
            if(node->left!=NULL){
                q.push({node->left,hlvl-1});
                lvl[node->left]=curlvl+1;
            }
            if(node->right!=NULL){
                q.push({node->right,hlvl+1});
                lvl[node->right]=curlvl+1;
            }

        }
        if(!checkPalindrome(temp))return false;
        return true;
    }
};