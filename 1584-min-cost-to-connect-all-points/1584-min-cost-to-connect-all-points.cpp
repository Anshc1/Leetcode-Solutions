class Solution {
public:
    
    int minCostConnectPoints(vector<vector<int>>& a) {
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>q; 
        vector<int>vis(a.size() , 0 ), key(a.size() , 1e9); 
        q.push({0 , 0}); 
        int n = a.size(); 
        key[0] = 0  ; 
        int ans = 0; 
        while(!q.empty()){
            int u = q.top().second ;
            int d = q.top().first ;
            q.pop(); 
            if(vis[u]){
                continue; 
            }
            vis[u]= 1;
            ans += d; 
            for(int j = 0; j < n ; j++){
                if( j== u || vis[j]){
                    continue ; 
                }
                int mdis = abs(a[j][0] - a[u][0] ) + abs(a[j][1] - a[u][1]); 
                if(key[j] > mdis){
                    key[j] = mdis ; 
                    q.push({mdis , j}); 
                }
            }
        }
        return ans ; 
    }
};