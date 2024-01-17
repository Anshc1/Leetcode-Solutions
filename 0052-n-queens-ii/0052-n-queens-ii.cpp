class Solution {
public:
    int n ; 
    bool check(int a , int b , int x , int y){
        a-= x; 
        b-= y; 
        return ((abs(a) == abs(b)) ||(a == 0 ) || (b== 0 )) ;
    }
    int recur(int i , vector<vector<int>>&a  , int t  ){
        if(t == 0 ){
            return 1; 
        }
        if(i >=n ){
            return 0 ; 
        }
        int res  = 0 ;  
        for(int jj = 0; jj < n ; jj++){
            bool ok = 1 ; 
            for(int xx = 0 ; xx < n ; xx++){
                for(int yy = 0 ; yy < n ; yy++){
                    if(a[xx][yy]  && check(i , jj , xx , yy)){
                        ok = 0 ; 
                    }
                }
            }
            if(ok){
                a[i][jj] =1 ;  
                res+= recur(i+1, a , t-1); 
                a[i][jj] =0 ;  
            }
        }
        
        return res; 
    }
    int totalNQueens(int n) {
        this->n = n ; 
        vector<vector<int>>a(n , vector<int>(n , 0)) ; 
        return recur(0  , a , n); 
    }
};