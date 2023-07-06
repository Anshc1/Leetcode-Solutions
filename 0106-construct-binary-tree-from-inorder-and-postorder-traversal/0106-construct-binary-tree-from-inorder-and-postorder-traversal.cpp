class Solution {
public:
    
    int n ;  
    TreeNode* recur(map<int,int>&idx , int la ,int ra ,int lb ,int rb , vector<int>&a , vector<int>&b ){
        if(la > ra){
            return NULL; 
        }
        int k = idx[b[rb]]; 
        TreeNode* root = new TreeNode(); 
        root->val = b[rb] ; 
        
        if(la == ra || lb == rb){ 
            root->left = NULL; 
            root->right = NULL; 
            return root; 
        }
        root->right = recur(idx , k+1 , ra , rb -(ra - k) ,rb-1 , a, b); 
        root->left  = recur(idx , la, k-1 , lb , rb - (ra - k ) - 1 , a, b); 
        return root ; 
    }
    TreeNode* buildTree(vector<int>& a, vector<int>& b) {
        map<int,int>idx; 
        n = a.size(); 
        for(int i =0 ; i < n ; i++){
            idx[a[i]] = i ; 
        }
        return recur(idx , 0 , n-1, 0 , n -1 , a ,b); 
    }
};