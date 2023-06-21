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
     void dfs(TreeNode* u , vector<int>&ans){
        if(!u){
            return; 
        }
        dfs(u->left ,ans); 
        dfs(u->right, ans); 
        ans.push_back(u->val); 
    }
    vector<int> postorderTraversal(TreeNode* root) {
       vector<int>ans; 
        dfs(root , ans); 
        return  ans; 
    }
};