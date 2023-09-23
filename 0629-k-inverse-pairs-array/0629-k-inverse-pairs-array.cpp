class Solution {
public:
    int kInversePairs(int n, int k) {
        int dp[n+1][k+1] ; 
        memset(dp , 0 , sizeof(dp)); 
        dp[0][0] = 1; 
        int mod = 1e9+7; 
        for(int i = 1 ; i <= n ;i++){
            for(int j = 0 ; j <= k ; j++){
                for(int f = 0 ; f <= min(j , i-1) ; f++){
                    dp[i][j] += dp[i-1][j - f]; 
                    dp[i][j]%= mod; 
                }
            }
        }
        return dp[n][k] ; 
    }
};