class Solution {
public:
    using ll = long long ; 
    int sumSubseqWidths(vector<int>& a) {
        int n = a.size(); 
        sort(a.begin() , a.end()); 
        ll mn = 0 , mx = 0 ; 
        ll mod = 1e9+7;
        ll p[n+1] ; 
        p[0] = 1;
        for(int i = 1; i <=n ; i++){
            p[i] = (p[i-1]*2)%mod; 
        }
        for(int i = 0 ; i < n ; i++){
            ll t = a[i]; 
            mn += (p[n-1-i]*t)%mod; 
            mn%=mod; 
        }
        for(int i = n-1 ; i >= 0  ; i--){
            ll t = a[i]; 
            mx += (p[i]*t)%mod;
            mx%=mod; 
        }
        ll ans = (mx - mn + mod )%mod; 
        return ans; 
    }
};

//-4-4-3 +1 + 4  + 12 