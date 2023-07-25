/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
const int N = 501; 
vector<vector<int>>adj(N+1);  
class Solution {
public:
    vector<int>ans; 
    void dfs(TreeNode* u  , int p ){
        if(!u){
            return  ; 
        } 
        if(u->left!= NULL){   
        adj[u->val].push_back(u->left->val);
        adj[u->left->val].push_back(u->val); 
        }
        if(u->right!= NULL){   
        adj[u->val].push_back(u->right->val);
        adj[u->right->val].push_back(u->val); 
        }
        dfs(u->left , u->val); 
        dfs(u->right , u->val); 
    }
    void dfs1(int u  ,  int p ,int dis , int k  ){
        //cout<< u << " " << p <<endl; 
        if(dis == k ){
            ans.push_back(u); 
            return; 
        }
        for(auto i : adj[u]){
            if(i!= p ){
                dfs1(i , u , dis+1, k ); 
            }
        }
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        for(int i = 0; i <= 500 ; i++ ){
            adj[i].clear() ; 
        }
        
        dfs(root, -1);   
        
        ans.clear(); 
        dfs1(target->val, -1, 0 , k ); 
        return ans; 
    }
};