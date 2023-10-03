class Solution {
public:
    int n ; 
    int dp[100000][2]; 
    int recur(int i , int prev , vector<int>&a ,vector<int>&b){
        if(i == n ){
            return  0; 
        }
        if(dp[i][prev]!=-1){
            return dp[i][prev]; 
        }
        int p ,q ;
        if(prev){
            p = b[i-1]; 
            q = a[i-1]; 
        }else{
            p = a[i-1]; 
            q = b[i-1]; 
        }
        int res =1e9 ; 
        if(a[i] > p && b[i] > q ){
            res = min(res , recur(i+1, 0 , a , b)); 
        }
        if(b[i] > p &&  a[i] > q ){
            res = min(res , 1 + recur(i+1, 1 , a , b)); 
        }
        return dp[i][prev] = res; 
    }
    int minSwap(vector<int>& a, vector<int>& b) {
        n = a.size(); 
        memset(dp , -1 ,sizeof(dp)); 
        return min(recur(1 , 0 , a , b) , 1 + recur(1 , 1, a, b)); 
    }
};