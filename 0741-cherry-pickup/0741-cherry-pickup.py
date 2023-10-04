class Solution:
    def cherryPickup(self, a: List[List[int]]) -> int:
        self.n = len(a)
        self.m = len(a[0])
        self.dp = [[[-1 for _ in range(51)] for _ in range(51)] for _ in range(51)]

        def recur(p, q, y):
            x = p + q - y
            if x >= self.n or y >= self.m or p >= self.n or q >= self.m or a[p][q] == -1 or a[x][y] == -1:
                return float('-inf')
            if self.dp[p][q][x] != -1:
                return self.dp[p][q][x]
            if p == self.n - 1 and q == self.m - 1:
                return a[self.n-1][self.m-1]
            
            k = a[p][q] + a[x][y]
            if p == x and q == y:
                k -= a[p][q]
            
            res = -1e5
            res = max(res, k + recur(p + 1, q, y))
            res = max(res, k + recur(p, q + 1, y))
            res = max(res, k + recur(p + 1, q, y + 1))
            res = max(res, k + recur(p, q + 1, y + 1))

            self.dp[p][q][x] = res
            return res

        return max(0, recur(0, 0, 0))
