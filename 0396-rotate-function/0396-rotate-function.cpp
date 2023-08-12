class Solution {
public:
    int maxRotateFunction(vector<int>& a) {
        int n = a.size(); 
        int pref[n+1]; 
        pref[0] = 0 ;          
        for(int i =0 ;i < n ; i++ ){
            pref[i+1] = pref[i] + a[i]; 
        } 
        int ans= 0 ; 
        for(int i =0 ; i < n ; i++){
            ans += a[i] * i ; 
        }
        int res = ans ; 
        int curr = ans ; 
        int prev = 0 ; 
        int s = 0; 
        for(int i = 0; i < n ; i++){
            curr -= (pref[n] - pref[i+1]);
            prev -= s ; 
            prev+= (n-1)*a[i]; 
            s+= a[i];
            ans = max(ans, prev + curr);  
        }
        return  ans; 
    }
};