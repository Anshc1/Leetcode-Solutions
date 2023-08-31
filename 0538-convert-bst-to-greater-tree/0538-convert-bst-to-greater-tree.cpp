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
    map<int,TreeNode*>x ; 
    void dfs(TreeNode* u ){
        if(u==NULL){
            return ; 
        }
        x[u->val] = u ; 
        dfs(u->left);
        dfs(u->right);
    }
    TreeNode* convertBST(TreeNode* root) {
        dfs(root); 
        int sum =0; 
        
        for(int i =1e4  ;i>=-1e4 ; i--){
            if(x[i]==NULL){
                continue; 
            }
            sum+= i ; 
            TreeNode* curr = x[i]; 
            curr->val =sum;
        }
        return root; 
    }
    
    
};