class Solution {
public: 
    int ladderLength(string a, string b, vector<string>& s) {
        queue<string>q ;
        map<string ,int >vis ; 
        map<string,int>dis; 
        set<string>x; 
        for(auto i : s){
            x.insert(i);  
            dis[i] = 1e8;  
        }
        dis[b] = 1e8; 
        dis[a] = 0 ; 
        q.push(a); 
        while(!q.empty()){
            
            for(int f =0 ;f <q.size() ; f++){
                
            auto t =q.front();
            q.pop(); 
            int d = dis[t]; 
            for(int i = 0 ; i < t.size() ; i++){
                char m = t[i]; 
                for(char j = 'a' ; j<= 'z' ; j++){
                    t[i] = j ; 
                    if(x.find(t)!= x.end() &&  !vis[t]){
                        dis[t] = min(dis[t] ,d+1 ); 
                        vis[t] = 1; 
                        q.push(t); 
                    }
                }
                t[i] = m ; 
            }
            }
        }
        if(dis[b] == 1e8){
            return 0 ; 
        }
        return dis[b]+1; 
    }
};