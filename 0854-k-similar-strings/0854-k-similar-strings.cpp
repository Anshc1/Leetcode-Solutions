class Solution {
public:
    int kSimilarity(string A, string B) {
        if (A == B) return 0;

        unordered_set<string> vis;
        queue<string> q;
        q.push(A);
        vis.insert(A);
        
        int res = 0;

        while(!q.empty()) {
            res++;
            for (int sz = q.size(); sz > 0; sz--) {
                string s = q.front();
                q.pop();
                
                int i = 0;
                while (s[i] == B[i]) i++;
                
                for (int j = i+1; j < s.length(); j++) {
                    if (s[j] == B[j] || s[j] != B[i]) continue;
                    string temp = swap1(s, i, j);
                    if (temp == B) return res;
                    if (vis.find(temp) == vis.end()) {
                        q.push(temp);
                        vis.insert(temp);
                    }
                }
            }
        }

        return res;
    }

    string swap1(string s, int i, int j) {
        swap(s[i], s[j]);
        return s;
    }
};
