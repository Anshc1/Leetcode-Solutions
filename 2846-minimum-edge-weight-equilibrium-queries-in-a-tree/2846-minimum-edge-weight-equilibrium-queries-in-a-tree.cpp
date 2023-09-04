class Solution {
public:

    int par[25][10001];
    vector < vector<pair<int, int>>>adj ;
    vector<int>depth;
    void dfs(int u , int p ) {
        par[0][u] = p;
        for (int i = 1 ; i < 24 ; i++) {
            par[i][u] = par[i - 1][par[i - 1][u]];
        }
        for (auto [i , len] : adj[u]) {
            if (i != p) {
                depth[i] = depth[u] + 1;
                dfs(i , u );
            }
        }
    }
    int query(int a , int b) {
        if (depth[a] < depth[b]) {
            swap(a , b);
        }
        for (int i = 24 ; i >= 0 ; i--) {
            if (depth[par[i][a]] >= depth[b]) {
                a = par[i][a];
            }
        }
        if (a == b) {
            return a ;
        }
        for (int i = 24 ; i >= 0 ; i--) {
            if (par[i][a]  != par[i][b]) {
                a = par[i][a];
                b = par[i][b];
            }
        }
        return par[0][a];
    }
    vector<vector<int>>pref ;
    void dfs1(int u , int p) {
        
        for (auto [i , len] : adj[u]) {
            if (i != p ) {
                pref[i] = pref[u];
                pref[i][len]++;
                dfs1(i , u ); 
            }
        }
        return;
    }
    vector<int> minOperationsQueries(int n, vector<vector<int>>& e, vector<vector<int>>& q) {
        adj.assign(n + 1 , {});
        depth.assign(n + 1 , 0 );
        for (auto u : e) {
            adj[u[0]].push_back({u[1] , u[2]});
            adj[u[1]].push_back({u[0] , u[2]});
        }
        pref.assign(n+1 , vector<int>(27 , 0)); 
        dfs(0, 0);
        dfs1(0 , 0); 
        int m = q.size();  
        vector<int>ans; 
        
        for(int i =0 ; i < m ; i++){
            int mx = 0 ;
            int t = 0;  
            int lca = query(q[i][0] , q[i][1]) ;
            int a = q[i][0];
            int b = q[i][1]; 
            //cout<< a << ' ' << b << " " << lca << endl; 
            for(int j = 0; j < 27 ; j++){
                int z   = -2*pref[lca][j] + pref[a][j] + pref[b][j];
                mx = max(z ,mx); 
            }
            
            t =  depth[a] + depth[b] - 2*depth[lca]; 
            ans.push_back(t - mx);
        }
        return ans; 
    }
};