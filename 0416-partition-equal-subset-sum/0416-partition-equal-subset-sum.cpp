class Solution {
public:
    bool canPartition(vector<int>& a) {
        int n = a.size();
        int sum = 0;
        for (int i = 0 ; i < n ; i++) {
            sum += a[i];
        }
        int dp[n+1][sum+1]; 
        memset(dp , 0 , sizeof(dp)); 
        dp[0][0] = 1;
        
        for (int i = 0; i < n ; i++) {
            for (int k = 0 ; k <= sum ; k++) {
                dp[i + 1][k] |= dp[i][k];
                if (dp[i][k] && k+a[i] <= sum) {
                    dp[i + 1][k + a[i]] |= 1 ;
                }
            }
        }
       
        if (sum % 2) {
            return 0 ;
        }
        return dp[n][sum / 2] ;
    }
};