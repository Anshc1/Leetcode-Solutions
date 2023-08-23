/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    map<int,int>x; 
    int sz =0; 
    Solution(ListNode* head) {
        ListNode* curr = head; 
        int idx = 0 ; 
        while(curr != NULL){
            x[idx] = curr->val ; 
            curr = curr->next;
            idx++; 
            sz++; 
        }
    }
    
    int getRandom() {
        int r = rand()%sz; 
        return x[r]; 
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */