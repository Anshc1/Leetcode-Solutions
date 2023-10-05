class Solution {
    public int longestPalindromeSubseq(String s) {
        int n = s.length(); 
        int [][]dp = new int[n+1][n+1]; 
        dp[0][0] = 1; 
        int ans = 1 ; 
        for(int i = 1; i < n ; i++){
            dp[i][i] = 1; 
            for(int j = i-1; j >= 0  ; j--){
                dp[i][j] = Math.max(dp[i-1][j] , dp[i][j+1]);
                if(s.charAt(i) == s.charAt(j)){
                    if(i - j > 1 ){
                        dp[i][j] = Math.max(dp[i][j] , dp[i-1][j+1] + 2); 
                    }else{
                        dp[i][j] = 2; 
                    }
                }
            }
        }
        for(int i = 0 ; i <  n  ; i ++){
            for(int j = 0 ; j < n ; j++){
                ans = Math.max(ans, dp[i][j]); 
            }
        }
        return ans ; 
        
    }
}