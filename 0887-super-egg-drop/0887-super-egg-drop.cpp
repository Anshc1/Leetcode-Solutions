class Solution {
public:
    int dp[10001][101]; 
    int recur(int n , int k ){
        if(n == 0 || n == 1){
            return  n ; 
        }
        if(k == 1){
            return n ; 
        }
        if(dp[n][k] !=-1){
            return dp[n][k]; 
        }
        int l = 1 , r = n , res = 1e6; 
        while(l <= r){
            int mid = (l+r)>>1; 
            int ll = recur(mid-1, k-1) ;
            int rr = recur(n - mid , k ); 
            res = min(res , 1 + max(rr , ll)); 
            if(ll < rr){
                l = mid+1; 
            }else{
                r = mid-1; 
            }
        }
        return dp[n][k] = res ; 
    }
    int superEggDrop(int k, int n) {
        memset(dp , -1, sizeof(dp)); 
        return recur(n , k ); 
    }
};