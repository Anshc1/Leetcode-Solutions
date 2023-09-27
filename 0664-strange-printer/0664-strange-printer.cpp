class Solution {
public:
    int dp[101][101]; 
    int n ; 
    int recur(int i , int j , string&s ){
        if( i == j ){
            return 1 ; 
        }
        if(dp[i][j] != -1){
            return dp[i][j]; 
        }
        int ans ; 
        if(s[i] == s[i+1] || s[i]== s[j]){
            ans = recur(i+1 , j , s);
        }else if(s[j] == s[j-1] ){
            ans = recur(i , j-1 , s); 
        }else{
            ans = recur(i , j-1 , s) +1; 
            for(int k = i+1 ;k < j ; k++){
                if(s[k]== s[j]){
                     ans = min(ans, recur(i , k-1 , s) + recur(k , j-1 , s)); 
                }
            }
        }
        return dp[i][j] = ans; 
        
    }
    int strangePrinter(string s) {
        n = s.size(); 
        memset(dp , -1, sizeof(dp)); 
        return recur(0 , n-1 , s ); 
    }
};