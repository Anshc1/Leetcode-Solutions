class Solution {
public:
    static const int N = 2001; 
    int dp[N][N]; 
    bool recur(int i , int j , string&s , string&p){
        if(i >= s.size() && j >= p.size()){
            return 1 ; 
        }
        if(j >= p.size() && i < s.size()){
            return 0  ; 
        }
        if(dp[i][j]!= -1){
            return dp[i][j]; 
        } 
        bool res = 0 ; 
        if(i >= s.size()){
            if(p[j]!= '*' ){
                return dp[i][j] =  0 ; 
            }else{
                return dp[i][j] = recur(i , j+1 , s , p ); 
            }
        }
        if(p[j] == '*'){
            if(i<s.size()){
                res |= recur(i+1 , j , s , p ); 
            }
            res |= recur(i , j+1 , s , p ); 
        }else if(p[j] == '?'){
            res |=  recur(i+1 , j+1 , s, p); 
        }else{
            if( (i>= s.size()) ||(s[i] != p[j])){
                res = 0 ; 
            }else{
                res |= recur(i+1 , j+1 , s , p ); 
            }
        }
        return dp[i][j] =  res; 
    }
    bool isMatch(string s, string p) {
        int mx = max(s.size() , p.size()); 
        for(int i = 0 ; i <= mx ; i++ ){
            for(int j = 0; j <=mx ; j++){
                dp[i][j] = -1; 
            }
        }
        return recur(0 , 0 , s , p ) ;
    }
};