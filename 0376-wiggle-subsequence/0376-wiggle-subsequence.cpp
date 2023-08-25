class Solution {
public:
    int wiggleMaxLength(vector<int>& a) {
        int n = a.size(); 
        vector<vector<int>>dp(n+1, vector<int>(2 , 1 ));  
        int ans = 0 ; 
        for(int i = 0; i < n ; i++){
            for(int j = i-1; j >= 0  ; j--){
                if(a[j] > a[i] ){
                    dp[i+1][0] = max(dp[i+1][0] , dp[j+1][1] + 1); 
                }
                if(a[j] < a[i] ){
                    dp[i+1][1] = max(dp[i+1][1] , dp[j+1][0] + 1); 
                }
            }
            ans = max(ans , max(dp[i+1][0] , dp[i+1][1]) ); 
        }
        return ans ; 
    }
};