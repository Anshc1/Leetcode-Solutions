class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        int n = p.size();
        priority_queue<int>pq; 
        vector<pair<int,int>>a(n);
        for(int i = 0 ;i < n ; i++){
            a[i] = {c[i] , p[i]}; 
        }
        sort(a.begin() , a.end()); 
        int idx = 0; 
        while(k > 0 ){
            while(idx < n  && a[idx].first <=w ){
                pq.push(a[idx].second);
                idx++; 
            }
            if(pq.empty()){
                break ; 
            }
            int t = pq.top(); 
            //cout<< t<<endl; 
            if(t < 0 ){
                break ; 
            }
            w+= t; 
            k--; 
            pq.pop(); 
        }
        return w; 
    }
};