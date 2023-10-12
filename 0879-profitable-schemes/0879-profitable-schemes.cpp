class Solution {
public:
    int n ; 
    int mx ; 
    vector<int>g , p ;
    int mod = 1e9+7; 
    using ll = long long ;
    int dp[101][101][101]; 
    ll recur(int i , int minp , int t){
        if(t > mx){
            return 0 ; 
        }
        if(i == n ){
            //cout<< t << endl; 
            if(t <= mx && minp == 0 ){
                return 1; 
            }
            return 0 ; 
        }
        //cout<< i << " " << minp << " " << t <<endl; 
        if(dp[i][minp][t] != -1){
            return dp[i][minp][t]; 
        }
        ll res = 0; 
        res += recur(i +1 , max(0, minp-p[i] ) , t + g[i]);
        res%=mod ; 
        res += recur(i +1 , minp , t );
        res%= mod; 
        return dp[i][minp][t] =  res%mod; 
    }
    int profitableSchemes(int m, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp , -1, sizeof(dp)); 
        g = group; 
        p = profit; 
        mx = m ;
        n = g.size(); 
        return recur(0 , minProfit , 0 ); 
    }
};