class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        priority_queue<pair<int,pair<int,int>>>q ; 
        for(int i = 0 ; i < a.size() ; i++){
            q.push({ -(a[i] + b[0]) , {i , 0}}); 
        }
        vector<vector<int>>ans; 
        while(k-- && !q.empty()){
            auto t = q.top(); 
            q.pop(); 
            ans.push_back({a[t.second.first] , b[t.second.second]});
            if(t.second.second+1 >= b.size()){
                continue; 
            } 
            pair<int,pair<int,int>> f = {-a[t.second.first] - b[t.second.second+1] , {t.second.first , t.second.second+1} }; 
            q.push(f); 
        }
        return ans; 
    }
};