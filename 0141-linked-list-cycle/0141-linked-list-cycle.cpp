/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode* ,int>x; 
        ListNode *ptr = head;
        int ct = 1e6 ;  
        while(ptr){
            if(x[ptr] == 1){
                return 1; 
            }
            x[ptr] = 1; 
            ptr = ptr->next; 
        } 
        return 0 ;   
    }
};