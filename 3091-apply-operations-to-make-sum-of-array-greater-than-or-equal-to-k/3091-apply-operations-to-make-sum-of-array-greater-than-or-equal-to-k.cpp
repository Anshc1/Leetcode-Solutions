class Solution {
public:
    int minOperations(int k) {
        int ans = 1e9 ; 
        for(int i = 0 ; i <= k ; i++){
            int x = 1 + i ; 
            ans = min(ans , (((k-x) + x - 1)/x) + i ) ;
        }
        return ans ; 
    }
};