class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int n  = s.size(); 
        long long dp[n][n][4]; 
        memset(dp , 0 , sizeof(dp)); 
        for(int i =0 ;i < n ; i++){
            for(int j = 0; j < 4 ; j++){
                dp[i][i][s[i]-'a'] = 1; 
            } 
        }
        int mod = 1e9+7 ; 
        for(int j = 1 ; j < n ; j++){
            for(int i =j-1 ; i >= 0  ; i--){
                for(int a = 0 ; a < 4 ; a++){
                    if(s[i] == s[j] && s[j]-'a' == a){
                        dp[i][j][a] = 2; 
                        for(int k =0 ; k < 4 ; k++){
                            dp[i][j][a] += (j - i >1 ? dp[i+1][j-1][k] : 0 ) ;
                            dp[i][j][a]%=mod; 
                        } 
                    }else{
                        dp[i][j][a] +=  (dp[i+1][j][a])%mod ; 
                        dp[i][j][a] +=  (dp[i][j-1][a])%mod;
                        dp[i][j][a] -=  (dp[i+1][j-1][a])%mod;  
                    }
                }
            }
        }
        long long ans =0 ; 
        for(int i =0 ;i <4 ; i++){
            ans+= dp[0][n-1][i]; 
            ans%=mod; 
            
        }
        return (int)ans; 
    }
};