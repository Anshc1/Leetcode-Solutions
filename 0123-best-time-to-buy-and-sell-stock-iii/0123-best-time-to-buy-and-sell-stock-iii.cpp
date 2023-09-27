class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size(); 
        vector<int>r(n); 
        r[n-1] = 0 ; 
        int mx = a[n-1]; 
        int ans =0 ; 
        for(int i = n-2; i>= 0 ; i--){
            r[i] = r[i+1];  
            r[i] = max(r[i] , mx - a[i] ); 
            ans= max(ans ,r[i]); 
            mx = max(mx , a[i]); 
        }
        int mn =a[0] ; 
        vector<int>l(n ,0 ); 
        for(int i = 1 ; i < n ; i++){
            l[i] = l[i-1]; 
            l[i] = max(l[i-1] , a[i] - mn);
            ans = max(ans , l[i]); 
            mn = min(mn , a[i]) ; 
        }
        for(int i =1 ; i < n; i++){
            ans = max(ans, l[i-1] + r[i]); 
        }
        return ans; 
    }
};