class Solution {
public:
    int n ; 
    int dp[200000][16]; 
    int recur(int mask , int idx ){
        if(idx == n){
            return 1;
        }
        if(dp[mask][idx]!= -1){
            return dp[mask][idx]; 
        }
        int res = 0; 
        for(int i = 0 ; i < n ; i++){
            if(!((mask>>i)&1)){
                if(((i+1)%(idx+1) == 0) || ((idx+1)%(i+1) == 0 )){
                    res+= recur(mask|(1<<i) , idx+1); 
                }
                //cout<< idx<< " "<< i <<mask << endl; 
            }
        }
        return dp[mask][idx] = res; 
    }
    int countArrangement(int m) {
        n = m ; 
        memset(dp , -1, sizeof(dp)); 
        return recur(0 , 0 ); 
    }
};