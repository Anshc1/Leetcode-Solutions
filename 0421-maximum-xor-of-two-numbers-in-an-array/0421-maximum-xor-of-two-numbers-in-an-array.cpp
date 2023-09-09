class Solution {
public:
    class Tries {
        public : 
        Tries* children[2] ={NULL, NULL};
    
        
        void insert(int num ) {
            Tries* root = this ;
            for (int j = 30 ; j >= 0 ; j--) {
                int bit =(num >> j )&1; 
                if(root->children[bit] == NULL){
                    Tries*curr =new Tries(); 
                    root->children[bit] = curr;
                    root = curr; 
                }else{
                    root = root->children[bit]; 
                }
            }
        }
        bool find(int num ){
            Tries *root = this; 
            for(int j = 30 ;j>= 0; j--){
               int bit = (num>>j)&1 ; 
               if(root->children[bit] == NULL){
                   return 0 ; 
               }else{
                   root = root->children[bit]; 
               }
            }
            return 1; 
        }
    };
    int findMaximumXOR(vector<int>& a) {
        
        int n = a.size(); 
        Tries *root = new Tries(); 
        for(auto i : a){
            root->insert(i); 
        }
        int ans = 0 ; 
        for(int i =0 ;i < n ;i++){
            int res = 0; 
            Tries* curr = root; 
            for(int j = 30 ; j>= 0 ; j--){
                bool bit = (a[i]>>j)&1;
                if(curr->children[!bit]==NULL){
                    curr = curr->children[bit];
                }else{
                    curr = curr->children[!bit];
                    res+= 1<<j ; 
                }
            }
            ans =max(ans,res); 
        }
        return ans ;  
    }
};
