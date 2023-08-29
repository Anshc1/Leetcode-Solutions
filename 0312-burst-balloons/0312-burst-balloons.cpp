class Solution {
public:
    int dp[302][302]; 
    int n ; 
    int recur(int i , int j , vector<int>&a ){
        if(i > j  ){
            return 0 ; 
        }
        if(dp[i][j] != -1){
            return dp[i][j]; 
        }
        int res = 0 ; 
        for(int k = i ; k <= j ; k++){
         res = max(a[k] *a[i-1] * a[j+1] + recur(i , k-1 , a) + recur(k+1, j , a) ,res);
        }
        return dp[i][j] = res; 
    }
    int maxCoins(vector<int>& a) {
        if(n==1){
            return a[0]; 
        }
        a.insert(a.begin() , 1); 
        a.push_back(1);
        n=a.size();
        memset(dp , -1, sizeof(dp)); 
        return recur(1 , n-2 , a); 
    }
};