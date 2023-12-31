class Solution {
public:
    int wiggleMaxLength(vector<int>& a) {
        int n = a.size(); 
        vector<vector<int>>dp(n+1, vector<int>(2 , 1 ));  
        int ans = 1 ; 
        for(int i = 1; i < n ; i++){
            if(a[i] == a[i-1]){
                dp[i][0] = dp[i-1][0]; 
                dp[i][1] = dp[i-1][1]; 
            }else if(a[i] > a[i-1]){
                dp[i][1] = dp[i-1][0]+1;
                dp[i][0] = dp[i-1][0]; 
            }else{
                dp[i][1] = dp[i-1][1]; 
                dp[i][0] = dp[i-1][1] +1 ; 
            }
            ans = max(ans , max(dp[i][0] , dp[i][1]) ); 
        }
        return ans ; 
    }
};