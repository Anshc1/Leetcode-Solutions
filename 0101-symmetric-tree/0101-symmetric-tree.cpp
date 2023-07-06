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
      void dfs1(TreeNode* u , vector<pair<int,int>>&x , int t){
        if(!u){
            return ; 
        }
        x.push_back({u->val , t } );
        dfs1(u->left , x , 0 ); 
        dfs1(u->right , x , 1); 
    }
    

    void dfs2(TreeNode* u , vector<pair<int,int>>&x , int t){
        if(!u){
            return ; 
        }
        x.push_back({u->val , t } );
        dfs2(u->right , x , 0); 
        dfs2(u->left , x , 1 ); 
    }
    
    bool isSymmetric(TreeNode* root) {
        vector<pair<int,int>>a , b; 
        dfs1(root , a ,1); 
        dfs2(root , b ,1);
        for(auto i : b){
            //cout<< i << " "; 
        }
        //cout<<endl; 
         for(auto i : a){
            //cout<< i << " "; 
        }
        //cout<<endl; 
        return a == b;
    }
};