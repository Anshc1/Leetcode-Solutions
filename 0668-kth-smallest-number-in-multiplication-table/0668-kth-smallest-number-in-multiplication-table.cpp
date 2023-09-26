class Solution {
public:
    int count_me(int mx , int m , int n ){
        int ct =0 ; 
        for(int i =1; i <= m ; i++){
            int x = mx / i ;
            x = min(n , x); 
            ct+= x; 
        }
        return ct; 
    }
    int findKthNumber(int m, int n, int k) {
        if(m < n ){
            swap(m , n ); 
        }
        int l = 1 ; 
        int r = m*n ;
        while(l  < r){
            int mid = (l+r)>>1; 
            int ct = count_me(mid, m , n );
            if(ct >= k ){
                r = mid; 
            }else{
                l = mid+1; 
            }
        }
        return r ; 
    }
};