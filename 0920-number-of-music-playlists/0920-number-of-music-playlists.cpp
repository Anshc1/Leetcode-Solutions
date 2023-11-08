class Solution {
public:
    using ll = long long ; 
    int mod  = 1e9+7; 
    int dp[101][101][101]; 
    ll recur(ll idx , ll u , ll v , ll k , ll g , int n ){
        ll res = 0; 
        if(idx == g){
            if(v == 0 ){
                return 1; 
            }
            return 0 ; 
        }
        if(dp[idx][u][v]!= -1){
            return dp[idx][u][v]; 
        }
        if(idx>= k ){
            res+= (u*recur(idx+1, u , v , k , g , n ))%mod; 
            res%=mod; 
            if(v > 0 ){
                res+= (v*recur(idx+1, u+1, v-1 ,  k , g, n ))%mod;
                res%= mod; 
            }
        }else{
            if(v>0){
                res+= (v*(recur(idx+1 , u , v-1 , k , g, n )))%mod;
                res%=mod; 
            }
        }
        return dp[idx][u][v]  = res ; 
    }
    int numMusicPlaylists(int n, int goal, int k) {
        memset(dp ,-1, sizeof(dp)); 
        return recur(0 , 0 , n , k , goal , n ); 
    }
};

// 1 2 3 1 2 3 4 5 6 2
