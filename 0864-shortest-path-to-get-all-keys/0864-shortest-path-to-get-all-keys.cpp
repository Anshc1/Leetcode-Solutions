class Solution {
public:
    vector<string>s ;
    int n , m ;
    vector<int> dx = {0 , 0 , -1 , 1};
    vector<int> dy = { -1 , 1 , 0 , 0 };
    using pii = pair<int, int>;

    bool check(int i , int j , int&mask) {
        if (i < 0  || j < 0 || i >= n || j >= m || s[i][j] == '#' ) {
            return 0 ;
        }
        if (s[i][j] == '@' || s[i][j] == '.') {
            return 1;
        }
        if (s[i][j] >= 'a' && s[i][j] <= 'z') {
            mask |= 1 << (s[i][j] -  'a');
            return 1;
        }
        if (mask & (1 << (s[i][j] - 'A'))) {
            return 1 ;
        }
        return 0 ;
    }
    int shortestPathAllKeys(vector<string>& grid) {
        s = grid;
        n = s.size();
        m = s[0].size();
        queue<pair<int, pii>>q;
        int sx , sy;
        int ct = 0;
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < m ; j++) {
                if (s[i][j] == '@') {
                    sx = i ;
                    sy = j ;
                }
                if (s[i][j] >= 'a' && s[i][j] <= 'z') {
                    ct++;
                }
            }
        }
        map<pair<int, pii> , int>vis ;
        map<pair<int, pii> , int>dis ;
        int mx = 1 << ct ;
        vis[ {0 , {sx , sy} }] = 1;
        q.push({0 , {sx , sy}});
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto t = q.front();
                q.pop();
                int x = t.second.first;
                int y = t.second.second;
                for (int i = 0 ; i < 4 ; i++) {
                    int px = x + dx[i];
                    int qx = y + dy[i];
                    int msk = t.first;
                    if (check(px , qx , msk)) {
                        if (!vis[ {msk , {px , qx}}]) {
                            vis[ {msk , {px , qx}}] = 1;
                            dis[ {msk , {px , qx}}] = dis[t] + 1 ;
                            pair<int, pii>pp = {msk , {px , qx}};
                            q.push(pp);
                            if (msk == mx - 1) {
                                return dis[ {msk , {px , qx}}];
                            }
                        }
                    }
                }
            }
        }
        return -1 ;
    }
};