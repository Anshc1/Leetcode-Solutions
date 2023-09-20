class Solution {
public:
    using ll = long long ; 
    ll minMoves2(vector<int>& a) {
          
        ll rsum = 0 ; 
        ll n = a.size(); 
        for(int i = 0; i < n ; i++){
            rsum+= a[i]; 
        }
        sort(a.begin() , a.end()); 
        ll lsum =0 ; 
        ll ans =1e18 ; 
        for(int i = 0 ; i < n ; i++){
            lsum+=a[i]; 
            rsum-=a[i]; 
            ll res = 1ll*a[i]*(i+1) - lsum ; 
            res += rsum - 1ll*a[i]*(n-1-i);
            ans = min(ans , res); 
        }
        return ans; 
    }
};