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
    int widthOfBinaryTree(TreeNode* root) {
        //left just double
        //right double-1
        int mul=1;
        long long ans=0;
        if(!root)return ans;
        queue<pair<TreeNode*,long long>> q;
        long long st=0,en=0;
        if(root->left){
            q.push({root->left,-1});
            st=-1;
        }
        if(root->right){
            q.push({root->right,1});
            en=1;
        }
        ans=max((long long)1,en-st);
        while(!q.empty()){
            int s=q.size();
            st=INT_MIN,en=INT_MIN;
            if(s==1){
                TreeNode* n=q.front().first;
                q.pop();
                if(n->left){
                    if(st==INT_MIN){
                        st=-1;
                    }
                    en=-1;
                    q.push({n->left,en});
                }
                if(n->right){
                    if(st==INT_MIN){
                        st=1;
                    }
                    en=1;
                     q.push({n->right,en});
                }
            }
            else{
                for(int i=0;i<s;i++){
                    TreeNode* n=q.front().first;
                    int c=q.front().second;
                    q.pop();
                    if(n->left){
                        if(st==INT_MIN){
                            if(c<0)st=2*c;
                            else st=2*c-1;
                        }
                        if(c<0)en=2*c;
                        else en=2*c-1;
                        q.push({n->left,en});
                    }
                    if(n->right){
                        if(st==INT_MIN){
                            if(c<0)st=2*c+1;
                            else st=2*c;
                        }
                        if(c<0)en=2*c+1;
                        else en=2*c;
                        q.push({n->right,en});
                    }
                }
            }
            if((st>0 && en>0) || (st<0 && en<0))ans=max(ans,en-st+1);
            ans=max(ans,en-st);
        }
        return ans;
    }
};