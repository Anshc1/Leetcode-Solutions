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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return head; 
        }
        ListNode* ptr = head ;
        int ct = 0 ; 
        while(ptr){
            ptr = ptr->next ; 
            ct++; 
        } 
        if(ct ==  n ){
            head = head->next; 
            return head ; 
        }
        ptr = head ; 
        n = ct - n-1 ;
        ct = 0 ; 
        while(ptr){
            if(ct == n){
                ptr->next =  ptr->next->next; 
            }
            ptr =  ptr->next ;
            ct++; 
        } 
        return head; 
    }
};