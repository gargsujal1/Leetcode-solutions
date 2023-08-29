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
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* curr=root;
        vector<int> ans;
        while(curr!=NULL){
            //If curr->left is null,we print node and move to right
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                //We first have to connect threads
                TreeNode* temp=curr->left;
                while(temp->right && temp->right!=curr){
                    temp=temp->right;
                }
                if(temp->right==NULL){
                 //we have to make thread
                    temp->right=curr;
                    ans.push_back(curr->val);
                    curr=curr->left;
                }
                else{
                    //thread is already present and we need to disconenct it
                    temp->right=NULL;
                    curr=curr->right;
                }
            }
            
        }
        return ans;
    }
};