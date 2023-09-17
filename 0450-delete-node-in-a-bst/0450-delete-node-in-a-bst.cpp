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
    TreeNode* dfs(TreeNode* u , int key  ) {
        if (u == NULL) {
            return NULL ;
        }
        if (key == u->val) {
            if(!u->left && !u->right){
                return NULL; 
            }
            if(u->left == NULL){
                return u->right; 
            }else if(u->right == NULL){
                return u->left; 
            }else{
                TreeNode * temp = u->right ;
                while(temp && temp->left != NULL){ 
                    temp= temp->left; 
                }
                u->val = temp->val ; 
                u->right = dfs(u->right , temp->val); 
            }
            
        } else if (key < u->val) {
            u->left = dfs(u->left , key);
        } else {
            u->right = dfs(u->right, key);
        }
        return u ; 
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
       
        return dfs(root , key);  
    }
};