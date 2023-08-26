class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& a, int k) {
        int n = a.size(); 
        int res = INT_MIN ; 
        int m = a[0].size(); 
        for(int l = 0 ;l < m ; l++){
            vector<int>b(n , 0 );
            for(int r = l; r < m ; r++ ){
                for(int i =0 ;i < n ; i++){
                    b[i] += a[i][r]; 
                }
                set<int>x ;
                x.insert(0); 
                int curr = 0; 
                for(int i = 0; i < n ; i++){
                    curr+= b[i];
                
                    if(x.lower_bound(curr - k )!= x.end()){
                       res = max(res, curr - *x.lower_bound(curr - k )); 
                    }   
                    
                    x.insert(curr); 
                }
                
                
            }
        }
        return res; 
    }
};