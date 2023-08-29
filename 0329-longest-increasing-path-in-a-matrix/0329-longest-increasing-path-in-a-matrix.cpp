class Solution {
public:
    int n , m ; 
    vector<int>di = {-1 ,1, 0 , 0 }; 
    vector<int>dj = {0 , 0 ,-1, 1}; 
    int dfs(int i , int j , vector<vector<int>>&a , vector<vector<int>>&dp ){
        int res = 0; 
        //cout<< i << " " << j <<endl; 
        if(dp[i][j] !=-1){
            return dp[i][j]; 
        }
        for(int k = 0; k < 4 ; k++){
            if(a[i][j]&(1<<k)){
                res = max(res , 1 + dfs(i+ di[k]  , j + dj[k] , a , dp)); 
            }
        }
        return dp[i][j] = res ; 
    }
    int longestIncreasingPath(vector<vector<int>>& a) {
        n = a.size(); 
        m = a[0].size();
    
        vector<vector<int>>b(n+2 , vector<int>(m+2 , -1)); 
        for(int i =0 ; i < n ; i++){
            for(int j = 0; j < m ;j++){
                b[i+1][j+1] = a[i][j]; 
            }
        }
    
        //cout<< "ok" ; 
        vector<vector<int>>x(n+2 , vector<int>(m+2 , 0 )) ;
        for(int i =1 ; i <= n ;i++){
            for(int j = 1 ; j<= m ; j++){
                //cout<< b[i][j] << " " ; 
                int val =0; 
                for(int k = 0 ; k < 4 ; k++){
                    int x = i+di[k]; 
                    int y = j+dj[k]; 
                    if(b[x][y] > b[i][j]){
                        val |= 1<< k ; 
                    }
                }
                
                x[i][j] = val; 
            }
            //cout<<endl; 
        }
       
        vector<vector<int>>dp(n+2 , vector<int>(m+2 , -1 ));
        int ans =0 ; 
        for(int i =1; i<= n ; i++){
            for(int j =1 ; j<= m ; j++){
                if(dp[i][j] == -1){
                    ans = max(ans , dfs(i , j , x, dp)); 
                }
            }
        }
        
        return ans+1; 
    }
};