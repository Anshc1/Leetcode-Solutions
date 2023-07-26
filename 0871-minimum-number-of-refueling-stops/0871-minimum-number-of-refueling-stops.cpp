class Solution {
public:
    int minRefuelStops(int t, int st, vector<vector<int>>& a) {
        priority_queue<int>q;
        int j = 0 ; 
        reverse(a.begin() , a.end()); 
        while(!a.empty() && a.back()[0] <= st ){
            q.push(a.back()[1]);
            a.pop_back(); 
        }
        int ans = 0 ;
        int pos = st; 
        while(!q.empty() && pos < t){
            int u = q.top();
            //cout<< u<<" "<< pos <<endl;   
            ans++; 
            pos += u ;
            q.pop(); 
            while(!a.empty() && a.back()[0] <= pos ){
                q.push(a.back()[1] );
                a.pop_back(); 
            }
        }
        if(pos < t){
            return -1; 
        }
        return ans; 
    }
};