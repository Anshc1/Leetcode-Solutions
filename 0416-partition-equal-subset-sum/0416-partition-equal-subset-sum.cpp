class Solution {
public:
    bool canPartition(vector<int>& a) {
        int n = a.size();
        int sum = 0;
        for (int i = 0 ; i < n ; i++) {
            sum += a[i];
        }
        vector<vector<int>>dp(n + 1, vector<int>(sum + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < n ; i++) {
            for (int k = 0 ; k <= sum ; k++) {
                dp[i + 1][k] |= dp[i][k];
                if (dp[i][k]) {
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