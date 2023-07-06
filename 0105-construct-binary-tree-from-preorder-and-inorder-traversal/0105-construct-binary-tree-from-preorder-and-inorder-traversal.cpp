class Solution {
public:
    
    int n ;  
    TreeNode* recur(map<int,int>&idx , int la ,int ra ,int lb ,int rb , vector<int>&a , vector<int>&b ){
        if(la > ra ){
            return NULL; 
        }
        int k = idx[b[lb]]; 
        TreeNode* root = new TreeNode(); 
        root->val = b[lb] ; 
        //cout<<root->val <<" ";
        //cout<<la << " " << ra <<endl; 
        //cout<<lb << " " << rb <<endl; 
        if(la == ra || lb == rb){
            //root->left =NULL;
            //root->right =NULL; 
            return root; 
        }
        
        root->left = recur(idx ,la,  k-1 , lb+1 , lb + (k -la ) ,a, b); 
        root->right= recur(idx ,k+1 , ra ,  lb +1 + (k - la) , rb ,a,b);
        
        return root ; 
    }
    TreeNode* buildTree(vector<int>& b, vector<int>& a) {
        map<int,int>idx; 
        n = a.size(); 
        for(int i =0 ; i < n ; i++){
            idx[a[i]] = i ; 
        }
        //reverse(a.begin() , a.end()); 
        return recur(idx , 0 , n-1, 0 , n -1 , a , b); 
    }
};