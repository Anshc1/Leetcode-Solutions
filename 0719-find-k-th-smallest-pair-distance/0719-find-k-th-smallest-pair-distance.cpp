class Solution {
public:
    int res ;
    bool check(vector<int>&a , int m , int k ){
        int n = a.size(); 
        int mx = 0 ; 
        int ct = 0; 
        for(int i = 0; i < n ; i++){
            int d = m + a[i] ;     
            int idx = upper_bound(a.begin() , a.end() , d) - a.begin(); 
            int t = idx - i - 1 ;
            ct+= t; 
            mx = max(mx , a[idx-1] - a[i]); 
        }
        res = mx; 
        return ct>= k ; 
    }
    int smallestDistancePair(vector<int>& a, int k) {
        int l =0 , r = 1e6+1; 
        sort(a.begin(),a.end());
        while( l < r){
            int mid = (l+r)/2; 
            if(check(a, mid , k )){
                r = mid ; 
            }else{
                l = mid+1; 
            }
        }
        
        
        check(a , r , k); 
        return res; 
    }
};