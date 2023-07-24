
const int N = 101 ; 
int dp[N+1][N+1]; 
class Solution {
public:
    
    bool dfs(int i , int j , string&s  ,string&t ,string & k ){
        
        int idx = i + j ; 
        if(idx == k.size()){
            return 1 ; 
        }
        if(dp[i][j] != -1){
            return dp[i][j] ;
        }
        bool res = 0 ; 
        if(i < s.size() && s[i] == k[idx] ){
            res|= dfs(i+1 , j , s ,t , k ); 
        }
        if(j <t.size() &&  t[j] == k[idx] ){
            res|= dfs(i ,j+1 ,s, t, k ); 
        }
        return dp[i][j] = res ; 
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size()){
            return  0 ; 
        }
        memset(dp ,-1 , sizeof(dp)); 
        return dfs(0 , 0 , s1, s2 ,s3); 
    }
};