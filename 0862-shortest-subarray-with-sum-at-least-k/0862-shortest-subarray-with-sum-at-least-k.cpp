class Solution {
public:
    int shortestSubarray(vector<int>& a, int k) {
        int n = a.size(); 
        vector<long long>pref(n+1 , 0 ); 
        for(int i = 0; i < n ; i++){
            pref[i+1] = pref[i] + a[i]; 
        }
        int ans =1e9; 
        deque<int>q; 
        for(int  i = 0 ;i < n ; i++){
            if(pref[i+1] >= k ){
                ans = min(ans, i+1); 
            }
            while(!q.empty() && pref[i+1] - pref[q.front()] >= k){
                ans = min(ans , i - q.front()+1); 
                q.pop_front(); 
            }
            while(!q.empty() && pref[i+1] < pref[q.back()]){
                q.pop_back(); 
            } 
            q.push_back(i+1); 
        }
        return ans == 1e9 ? -1 : ans; 
    }
};