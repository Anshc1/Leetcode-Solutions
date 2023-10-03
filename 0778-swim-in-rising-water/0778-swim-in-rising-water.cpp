class Solution {
public:
    int n , m ;
    vector<int>dx = {-1, 1 , 0 , 0 }, dy = {0 , 0 , -1, 1}; 
    bool bfs(int t , vector<vector<int>>&a){
        if(a[0][0] > t){
            return 0 ; 
        }
        vector<vector<int>>vis(n , vector<int>(m , 0 )); 
        queue<pair<int,int>>q; 
        q.push({0 , 0 }); 
        vis[0][0] = 1; 
        while(!q.empty()){
            auto u = q.front();
            q.pop(); 
            for(int i = 0; i  < 4 ; i++){
                int x  = u.first + dx[i]; 
                int y =  u.second+ dy[i];
                if(x>= 0 && x < n && y >=0 && y< m && !vis[x][y] && a[x][y] <=t){
                    vis[x][y] = 1; 
                    q.push({x, y});             
                }
            }
        }
        return vis[n-1][n-1]; 
    }
    int swimInWater(vector<vector<int>>& a) {
        n = a.size(); 
        m = n ; 
        int l = 0 , r = n*n+1 ;
        while(l  < r){
            int mid = (l+r)>>1; 
            if(bfs(mid , a)){
                r = mid; 
            }else{
                l = mid+1; 
            }
        }
        return r; 
    }
};