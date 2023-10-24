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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int ans=INT_MIN;
        vector<int> v;
        if(root==NULL){
            return v;
        }
        while(!q.empty()){
            auto f=q.front();
            q.pop();
            if(f==NULL){
                v.push_back(ans);
                ans=INT_MIN;
                if(!q.empty()) q.push(NULL);
            }
            else{
                ans=max(ans,f->val);
                if(f->left){
                    q.push(f->left);
                }
                if(f->right){
                    q.push(f->right);
                }
            }
        }
        return v;
    }
};