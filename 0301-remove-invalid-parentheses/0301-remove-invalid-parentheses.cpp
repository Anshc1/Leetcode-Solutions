class Solution {
public:


bool isValid(const string& s) {
    int count = 0;
    for (char c : s) {
        if (c == '(') count++;
        if (c == ')') count--;
        if (count < 0) return false; // More closing brackets than opening brackets
    }
    return count == 0;
}

vector<string> removeInvalidParentheses(string s) {
    vector<string> results;
    if (s.empty()) return {""};
    
    queue<string> q;
    unordered_set<string> visited;
    bool found = false;

    q.push(s);
    visited.insert(s);

    while (!q.empty()) {
        int size = q.size();
        unordered_set<string> currentLevel;

        for (int i = 0; i < size; i++) {
            string current = q.front();
            q.pop();

            if (isValid(current)) {
                results.push_back(current);
                found = true;
            }
            
            // If a valid sequence is found, no need to go to the next level
            if (found) continue;

            // Try removing each parenthesis
            for (int j = 0; j < current.size(); j++) {
                if (current[j] != '(' && current[j] != ')') continue;
                string next = current.substr(0, j) + current.substr(j + 1);
                if (visited.find(next) == visited.end()) {
                    q.push(next);
                    visited.insert(next);
                }
            }
        }

        // If we found a valid sequence, break
        if (found) break;
    }

    return results;
}

};