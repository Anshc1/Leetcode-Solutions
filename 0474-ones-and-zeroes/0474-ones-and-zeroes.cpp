class Solution {
public: 
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size(); 
        vector<vector<int>>ct(sz , vector<int>(2 , 0 )); 
        for(int i =0 ;i < sz ; i++){
            for(auto j : strs[i]){
                ct[i][j-'0']++; 
            }
        }
        int dp[sz+1][n+1][m+1];
        memset(dp , 0 , sizeof(dp));
        int ans =0 ; 
        for(int k =0 ; k < sz ; k++){
            for(int i =0 ;i <= n ; i++){
                for(int j =0 ;j <= m ; j++){
                    dp[k+1][i][j] = max(dp[k][i][j] , dp[k+1][i][j]); 
                    if(i + ct[k][1] <= n && j + ct[k][0] <= m ){
                        dp[k+1][i+ct[k][1]][j + ct[k][0]] =  max(dp[k][i][j] + 1 , dp[k+1][i+ct[k][1]][j + ct[k][0]]); 
                    }
                }
            }
            
        }
        for(int i = 0 ; i <= sz ;i++){
            for(int j = 0 ; j <= n ; j++){
                for(int k = 0; k <= m ; k++){
                    ans = max(ans , dp[i][j][k]); 
                }
            }
        }
        return ans; 
        
    }
};