class Solution {
public:
    int minimizeSet(int d1, int d2, int n, int m) {
        long long l = 1 , r = 1e12 ;
        
        while(l < r){
            long long mid = (l+r)>>1;  
            long long lcm = (long long)d1 * d2 ; 
            lcm/= __gcd(d1 , d2);
            int ct= mid/lcm ; 
            long long left = mid - ct ;
            //cout<< left << " " << mid <<endl;
            long long p = mid/d1 ; 
            long long q = mid/d2 ;
            p = mid - p ; 
            q = mid - q ;
            //cout << mid << " " << p << " " << q <<endl; 
            if(left >= m + n  && p >= n && q >= m  ){
                r = mid; 
            }else{
                l = mid+1; 
            } 
        }
        return r ; 
    }
    // 1 3 5 
};