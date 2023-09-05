class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>vis ,deg(n , 0 ) ; 
        
        for(auto e : edges){
            deg[e[1]]++; 
        }
        
        for(int i =0 ;i < n ; i++){
            if(deg[i] ==0 )
            {
                vis.push_back(i); 
            }
        }
        sort(vis.begin() , vis.end()); 
        return vis; 
    }
};