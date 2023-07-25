const int N = 500; 
int dp[N][N]; 
class Solution {
public:
    int recur(int i , int j , string&s){
        if(i >= j ){
            return 0 ; 
        }
        if(dp[i][j]!= -1){
            return dp[i][j] ; 
        }
        int res = 1e9 ; 
        if(s[i] == s[j]){
            res = min(res , recur(i+1 , j-1 , s));
        }else{
            res = min(res, 1 + recur(i+1 , j , s)); 
        }
        res = min(res , 1 + recur(i , j-1 , s)); 
        return dp[i][j] = res ;
    }
    int minInsertions(string s) {
        memset(dp , -1, sizeof(dp)); 
        int ans = recur(0 , s.size()-1 , s); 
        return ans; 
    }
};