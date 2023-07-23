//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends


const int N = 1e3+1 ; 
int dp[N][N]; 
int recur(int i  , int j , string&s ){
    if(i > j ){
        return 0 ; 
    }
    if(dp[i][j]!= -1){
        return dp[i][j]; 
    }
    int res = 0  ; 
    if(s[i] == s[j]){
        res = max(res, ((i == j )? 1 : 2) + recur(i+1 , j-1 , s) ); 
        res = max(res , recur(i , j-1  ,s ) ); 
    }else{
        res = max(res , recur(i+1 , j  , s ));
        res = max(res , recur(i , j-1, s)); 
    }
    
    return dp[i][j] =  res; 
}


int minDeletions(string s, int n) { 
    memset(dp ,-1, sizeof(dp)); 
    return n - recur(0 ,  n , s); 
} 