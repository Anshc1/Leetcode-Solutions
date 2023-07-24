class Solution {
public:
    int maximalSquare(vector<vector<char>>& b) {
        
        int n = b.size(); 
        int m = b[0].size(); 
        int a[n][m];
        for(int i =0 ;i < n ; i++){
            for(int j = 0 ;j < m ; j++){
                a[i][j] = b[i][j]-'0'; 
            }
        }
        vector<vector<int>>r(n , vector<int>(m , 0 )) , c(n , vector<int>(m , 0 )); 
        for(int i = 0; i <n ; i++ ){
            for(int j = 0 ;j < m ; j++){
                if(a[i][j] == 0 ){
                    r[i][j] = 0; 
                }else{
                    if(j > 0 ){
                        r[i][j] = r[i][j-1] ; 
                    }
                    r[i][j]++; 
                }
                
            }
            
        }
        
        for(int i = 0; i < m ; i++ ){
            for(int j = 0 ;j < n ; j++){
                if(a[j][i] == 0 ){
                    c[j][i] = 0; 
                }else{
                    if(j > 0 ){
                        c[j][i] = c[j-1][i] ; 
                    }
                    c[j][i]++; 
                }
               
            }
           
            
        }
       // cout<<"ok"<<endl; 
        int dp[n][m] ; 
        memset(dp ,0 , sizeof(dp)); 
        int ans =0 ; 
        for(int i = 0; i < n ; i++){
                dp[i][0] = a[i][0];
                ans = max(ans, a[i][0]); 
        }
        for(int j = 0; j < m ; j++){
                dp[0][j] = a[0][j]; 
                ans = max(ans, a[0][j]);  
        }
        for(int i = 1; i < n ; i++){
            for(int j = 1 ; j < m  ; j++  ){
                if(a[i][j] == 0 ){
//                    cout<<0 << " "; 
                    continue; 
                }
                dp[i][j] = min(dp[i-1][j-1] + 1 , min(r[i][j] , c[i][j]));
                ans =max(ans, dp[i][j] * dp[i][j]);
        
            }
            //cout<<endl; 
        }
        return ans; 
        
    }
};