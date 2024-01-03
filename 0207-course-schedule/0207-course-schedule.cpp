class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>deg(n , 0 ); 
        vector<vector<int>>adj(n); 
        for(int i = 0; i < pre.size() ; i++){
            deg[pre[i][0]]++;
            adj[pre[i][1]].push_back(pre[i][0]); 
        }
        int ct = 0; 
        queue<int>q; 
        for(int i = 0; i < n ; i++){
            if(deg[i] == 0 ){
                q.push(i); 
            }
        }
        
        while(!q.empty()){
            auto u = q.front();
            //cout<< u <<endl; 
            ct++; 
            q.pop(); 
            for(auto i : adj[u]){
                deg[i]-- ; 
                if(deg[i] == 0 ){
                    q.push(i); 
                }
            }
        }
        return ct == n ; 
    }
};