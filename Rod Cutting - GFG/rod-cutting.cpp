//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

const int N = 1001; 
int dp[N][N] ; 
class Solution{
  public:
    int n ; 
    int recur(int i , int j , vector<int>&p  ){
        if(i == n ){
            return p[n - j ]; 
        }
        if(dp[i][j]!= -1){
            return dp[i][j]; 
        }
        int res = max( p[ i - j + 1 ] +  recur(i+1 , i + 1 , p ) , recur(i+1 , j , p )); 
        return dp[i][j] =  res; 
    }
    int cutRod(int price[], int m) {
        n = m ; 
        memset(dp , -1 , sizeof(dp));
        vector<int>p(n+1 , 0 ); 
        for(int i = 0 ; i < n ; i++){
            p[i+1]= price[i];  
        }
        return recur(0 , 0 , p); 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends