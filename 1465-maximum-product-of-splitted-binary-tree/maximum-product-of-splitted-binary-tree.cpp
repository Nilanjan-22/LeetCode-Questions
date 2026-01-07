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
    vector<long long> v;
    int m=1e9+7;
    long long dfs(TreeNode* node){
        if(node==NULL)return 0;
        long long sum=0;
        sum+=dfs(node->left);
        sum+=node->val;
        sum+=dfs(node->right);
        v.push_back(sum);
        return sum;
    }
    int maxProduct(TreeNode* root) {

        long long sum= dfs(root);
        long long ans=-1;
        for(int i=0;i<v.size();i++){
            // long long mul=(sum-v[i])*v[i];
            // mul%=m;
            ans=max(ans, (sum-v[i])*v[i]);
            // ans%=m;
        }
        return ans%m;
    }
};