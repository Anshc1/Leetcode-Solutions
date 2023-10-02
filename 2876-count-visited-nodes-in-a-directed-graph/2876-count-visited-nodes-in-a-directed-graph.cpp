
class Solution {
public: 
    int vis[100001]; 
    int res[100001]; 
    
    void dfs(int u , int c , vector<vector<int>>&adj){
        vis[u] = 1;
        res[u] = 1; 
        for(auto i : adj[u]){
            if(!vis[i]){
                dfs(i , c , adj); 
                res[u] += res[i]; 
            }else{
                res[u] += res[i]; 
            }
        }
    }
    int ct =0 ; 
    void find_len(int u  , vector<vector<int>>&adj , vector<int>&q ){
        ct++; 
        vis[u] = 1;
        q.push_back(u); 
        for(auto i : adj[u]){
            if(vis[i] == 0 ){
                find_len(i , adj, q); 
            }
        }
    }
    vector<int> countVisitedNodes(vector<int>& e) {
        memset(vis, 0 , sizeof(vis));
        memset(res, 0 , sizeof(res));
        
        int n = e.size(); 
        
        vector<vector<int>>adj(n);
        vector<int>in(n , 0 );
        
        for(int i =0 ;i < n ; i++){
            adj[i].push_back(e[i]);
            in[e[i]]++; 
        }
        
        queue<int>q ;
        
        
        for(int i = 0 ; i< n ; i++){
            if(in[i] == 0 ){
                q.push(i); 
            } 
        }
        vector<int>nc; 
        while(!q.empty()){
            int t =q.front(); 
            nc.push_back(t); 
            q.pop(); 
            vis[t] = 1;             
            for(auto i : adj[t]){
                in[i]--; 
                if(in[i] == 0 ){
                    q.push(i); 
                }
            }
        }
        
        for(int i =0 ; i < n ; i++){
            if(!vis[i]){
                ct =0 ;
                vector<int>q; 
                find_len(i , adj, q );
                for(auto j : q){
                    res[j] = ct; 
                }       
            }
        }
        
        vector<int>ans;
        for(auto i : nc){
            vis[i] = 0; 
        }
        for(int i = 0 ;i < n ;i++){
            if(!vis[i]){
                dfs( i , i , adj ); 
            }
            ans.push_back(res[i]); 
        }
        return ans;  
    }
};