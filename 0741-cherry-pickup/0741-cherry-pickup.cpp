class Solution {
public:
    int n, m;
    int dp[51][51][51]; 

    int recur(int p, int q, int y, vector<vector<int>>& a) {
        int x = p + q - y;
        if (x >= n || y >= m || p >= n || q >= m || a[p][q] == -1 || a[x][y] == -1) {
            return INT_MIN; 
        }
        if (dp[p][q][x] != -1) {
            return dp[p][q][x];
        }
        if (p == n-1 && q == m-1) {
            return a[n-1][m-1]; 
        }
        
        int k = a[p][q] + a[x][y]; 
        if (p == x && q == y) {
            k -= a[p][q];
        }
        
        int res = -1e5; 
        res = max(res, k + recur(p+1, q, y, a));
        res = max(res, k + recur(p, q+1, y, a));
        res = max(res, k + recur(p+1, q, y+1, a));
        res = max(res, k + recur(p, q+1, y+1, a));

        return dp[p][q][x] = res;
    }

    int cherryPickup(vector<vector<int>>& a) {
        n = a.size();
        m = a[0].size();
        memset(dp, -1, sizeof(dp)); 
        return max(0, recur(0, 0, 0, a));
    }
};