class Solution {
public:
    int kSimilarity(string s1, string s2) {
        int n = s1.size();
        queue<string>q ;
        unordered_map<string, int>dis;
        unordered_map<string, int>vis;
        q.push(s1);
        vis[s1] = 1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string t = q.front();
                q.pop();
                int d = dis[t];
                for (int i = 0 ; i < n ; i++) {
                    if (t[i] != s2[i]) {
                        for (int j = i + 1 ; j < n ; j++) {
                            if (t[j] != s2[i] ) {
                                continue;
                            }
                            swap(t[i] , t[j]);
                            if (!vis[t]) {
                                vis[t] = 1;
                                if (dis[t] == 0 ) {
                                    dis[t] = d + 1 ;
                                } else {
                                    dis[t] = min(dis[t] , d + 1);
                                }
                                q.push(t);
                            }
                            swap(t[i] , t[j]);
                        }
                        break; 
                    }
                }
            }
        }
        return dis[s2];
    }
};