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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL)return 0;
        int ans=1,level=1;
        queue<TreeNode*> q;
        q.push(root);
        long long sum,maxsum=INT_MIN;
        while(!q.empty()){
            sum=0;
            int l=q.size();
            for(int i=0;i<l;i++){
                TreeNode* n=q.front();
                q.pop();
                sum+=n->val;
                if(n->left!=NULL)q.push(n->left);
                if(n->right!=NULL)q.push(n->right);
            }
            cout<<sum<<endl;
            if(maxsum<sum){
                maxsum=sum;
                ans=level;
            }
            level++;
        }

        return ans;

    }
};