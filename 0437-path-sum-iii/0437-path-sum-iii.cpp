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
    long long ans = 0 ; 
    void dfs1(TreeNode* u , long long sum , unordered_map<long long,int>ct , int t){
        if(u == NULL){
            return ; 
        }
        //cout<< u ->val<< endl; 
        sum+= u->val;
        //for(auto i : ct){
            //cout<< i.first << " " << i.second<<endl; 
        //}
        //cout<< sum << endl; 
        //cout<<"------------"<<endl; 
        ans+= ct[sum - t]; 
        //cout<< "ans " << ans<<endl; 
        ct[sum]++; 
        dfs1(u->left , sum , ct , t); 
        dfs1(u->right , sum , ct , t); 
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int>ct ; 
        ct[0] = 1 ; 
        dfs1(root , 0 , ct , targetSum); 
        return ans; 
    }
};