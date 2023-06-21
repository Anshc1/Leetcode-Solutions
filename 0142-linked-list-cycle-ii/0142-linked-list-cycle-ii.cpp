const int N = 1e4 + 1;
class Solution {
public:
    map<ListNode* , int>vis;
    ListNode *ans = NULL ;
    void dfs(ListNode*curr ) {
        if (curr) {
            if (vis[curr]) {
                if (ans == NULL) {
                    ans = curr ;
                }
            } else {
                vis[curr] = 1;
                dfs(curr->next);
            }
        }
    }
    ListNode * detectCycle(ListNode *head) {
        dfs(head);

        return ans;
    }
};


