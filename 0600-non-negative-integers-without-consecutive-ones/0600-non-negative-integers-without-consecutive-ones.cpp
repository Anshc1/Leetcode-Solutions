class Solution {
public:
    int dp[32][2][2]; 
    int recur(int bit , bool same , bool prev , int n){
        if(bit == -1){
            return 1; 
        }
        if(dp[bit][same][prev] != -1){
            return dp[bit][same][prev]; 
        }
        int curr =( n>>bit )&1; 
        int res = 0 ;
        if(prev){
            int sz = same ;
            if(curr){
                sz = 0 ; 
            }
            res+= recur(bit-1 , sz ,  0 , n  ); 
        }else{
            if(curr){
                res += recur(bit -1 , 0 , 0 , n  ); 
                res+= recur(bit-1 , same  , 1 , n ); 
            }else{
                res += recur(bit-1 , same ,  0, n ); 
                if(!same){
                    res += recur(bit-1 , same , 1 , n ); 
                }
            }
        }
        return dp[bit][same][prev] =  res ; 
    }
    int findIntegers(int n) {
        memset(dp , -1 , sizeof(dp)); 
        return recur(31 , 1, 0 , n); 
    }
};