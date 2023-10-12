class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long lcm = a*b ; 
        lcm/= __gcd(a , b); 
        long long l = 1, r = 1e18; 
        while(l  <r){
            long long mid = (l+r)>>1; 
            long long ct = mid/a + mid /b  ;
            ct -= mid/lcm ; 
            if(ct>= n ){
                r = mid; 
            }else{
                l = mid+1;
            }
        }
        int mod = 1e9+7; 
        return r%mod; 
    }
};