class Solution {
public:
    int b_s(int ll , int rr , vector<vector<int>>&a , int val ){
        int l = ll , r = rr ; 
        int mid ; 
        while(l < r){
            mid = (l+r)>>1; 
             
            if(a[mid][0] >= val ){
                r = mid ; 
            }else{
                l = mid+1; 
            }
        }
        return r ; 
    }
    int dp[(int)1e5+1]; 
    int n ; 
    int recur(int i , vector<vector<int>>&a ){
        if(i == n ){
            return 0 ; 
        }
        if(dp[i]!= -1){
            return dp[i]; 
        } 
        int next = b_s(i+1 , n , a , a[i][1]);
        int res = next - i -1 + recur(next , a);
        res = min(res , 1 + recur(i+1, a)) ; 
        return dp[i] = res; 
    }
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        n = a.size(); 
        sort(a.begin() , a.end()); 
        memset(dp ,-1 ,sizeof(dp)); 
        return recur(0 , a); 
    }
};