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
    int mx = 0 ; 
    map<int,int>ct; 
    int dfs(TreeNode* u  ){
        if(u == NULL){
            return 0 ; 
        }
        int val = u->val;
        val += dfs(u->left);
        val += dfs(u->right);
        ct[val]++; 
        mx = max(mx , ct[val]); 
        return val ;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>ans; 
        dfs(root);
        for(auto i : ct){
            if(i.second == mx){
                ans.push_back(i.first); 
            }
        }
        return ans; 
    }
};