
class Solution {
public:
    int n , m ;
    bool check(int i , int j ) {
        if (i >= 0 && i < n && j >= 0 && j < m ) {
            return 1;
        }
        return  0 ;
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& a) {
        n = a.size();
        m = a[0].size();
        bool ok = 1 ;
        vector<int>b ;
        for (int i = 0; i < n ; i++) {
            int dx = -1 , dy = 1;
            int x = i , y = 0 ;
            vector<int>temp ;
            while (check(x  , y )) {
                temp.push_back(a[x][y]);
                x += dx ;
                y += dy ;
            }
            if (ok) {
                for (auto j  : temp) {
                    b.push_back(j);
                }
            } else {
                while (!temp.empty()) {
                    b.push_back(temp.back());
                    temp.pop_back();
                }
            }
            ok = !ok ; 
        }
        for (int i = 1 ; i < m ; i++ ) {
            int dx = -1 , dy = 1;
            int x = n-1 , y = i;
            vector<int>temp ;
            while (check(x  , y )) {
                temp.push_back(a[x][y]);
                x += dx ;
                y += dy ;
            }
            if (ok) {
                for (auto j  : temp) {
                    b.push_back(j);
                }
            } else {
                while (!temp.empty()) {
                    b.push_back(temp.back());
                    temp.pop_back();
                }
            }
            ok = !ok ;
        }
        return b; 
    }
};