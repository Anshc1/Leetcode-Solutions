class Solution {
public:
    int dp[100001][3][2]; 
    int mod = 1e9+7; 
    int recur(int i , int l , int a , int n ){
        if(i == n){
            //cout<< a << endl; 
            return 1; 
        }
        if(dp[i][l][a] != -1){
            return dp[i][l][a]; 
        }
        int res =0 ; 
        if(a < 1){
            res += recur(i+1, 0 , a + 1 , n );
            res%=mod; 
        }
        if(l == 0 ){
            res+= recur(i+1, 1, a , n);
            res%=mod ; 
        }
        if(l == 1){
            res+= recur(i+1 ,2 ,a , n); 
            res%=mod; 
        }
        res += recur(i+1 , 0 , a ,n );
        res%=mod; 
        return dp[i][l][a] =  res ; 
    }
    int checkRecord(int n) {
        memset(dp , -1 , sizeof(dp)); 
        return recur(0 , 0 , 0, n); 
    }
};