class Solution {
public:
    int minMutation(string s, string t, vector<string>&bank ) {
        map<string, int > vis;
        queue<string>q;
        set<string>st;
        map<string ,int>dis; 
        if(s == t){
            return 0 ; 
        }
        for(auto i : bank ){
            st.insert(i); 
            dis[i] = 1e8; 
        }
        q.push(s); 
        dis[s] = 0 ; 
        vector<char>c = {'A' , 'C' , 'G' , 'T'}; 
        while(!q.empty()){
            auto u =q.front(); 
            q.pop(); 
            for(int i =0 ; i < 8 ; i++){
                for(int j = 0 ; j < 4 ; j++){
                    if(u[i] == c[j]){
                        continue; 
                    }
                    string m = u ;  
                    u[i] = c[j]; 
                    if(st.find(u) != st.end() && vis[u]== 0 ){
                        vis[u] = 1; 
                        q.push(u); 
                        dis[u] = min(dis[u] , dis[m]+1) ; 
                        cout<< u << endl; 
                    }else{
                    }
                    u = m ; 
                }
            }
        }
        if(dis[t] == 1e8 || dis[t] == 0 ){
            return -1; 
        }
        return dis[t]; 
    }
};