class Solution {
public:
    vector<int>dp; 
    vector<int>sz ; 
    int dfs1(int u ,int p , vector<vector<int>>&adj){
        dp[u] = 0 ; 
        sz[u] = 1; 
        for(auto i : adj[u]){
            if(i!= p ){
                sz[u] += dfs1(i, u , adj); 
                dp[u] += dp[i]+sz[i];
            }
        }
        return sz[u]; 
    }
    vector<int>ans; 
    void dfs2(int u , int p , vector<vector<int>>&adj){
        ans[u] = dp[u] ;
        for(auto i : adj[u]){
            if(i != p ){
                sz[u] -= sz[i]; 
                dp[u] -= dp[i] + sz[i];
                sz[i] += sz[u]; 
                dp[i] += dp[u] + sz[u]; 
                dfs2(i , u , adj); 
                dp[i] -= dp[u] + sz[u]; 
                sz[i] -= sz[u]; 
                dp[u] += dp[i] + sz[i]; 
                sz[u] += sz[i]; 
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        sz.assign(n, 0 ); 
        dp.assign(n ,0 ); 
        ans.assign(n , 0 ); 
        vector<vector<int>>adj(n); 
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs1(0 , -1, adj); 
        dfs2(0 , -1, adj); 
        return ans; 
    }
};