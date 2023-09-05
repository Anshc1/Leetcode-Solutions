class Solution {
public:
    int n ; 
    bool dfs(int u , int k , map<int,int>&idx , vector<vector<int>>&dp ,vector<int>&a){
        if(k>n || k < 0 ){
            return 0 ; 
        }
        //cout<< u << " "; 
 
        if(u == n ){
            return 1; 
        }
        if(dp[u][k]!= -1){
            return dp[u][k]; 
        }
        int res = 0 ; 
        for(int j = k-1; j<= k+1; j++){
            if(idx[j+a[u-1]]!= 0 && idx[j+a[u-1]] != u){
                res|= dfs(idx[j+a[u-1]] , j , idx , dp,a ); 
            }
        }
        return dp[u][k] =  res; 
    }
    bool canCross(vector<int>&a) {
        n = a.size(); 
        vector<vector<int>>dp(n+1 , vector<int>(n+1, -1)); 
        map<int,int>idx;
        for(int i =0 ;i < n ; i++){
            idx[a[i]] = i+1 ; 
        }
        return dfs(1 , 0, idx,dp , a ) ; 
    }
};