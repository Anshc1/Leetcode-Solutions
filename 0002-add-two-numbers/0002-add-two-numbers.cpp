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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode();
        ListNode *head = res;
        int c = 0 ;  
        int p = 0 ; 
        while(l1 || l2 || p >= 10){
            int x = 0  , y = 0   ; 
            if(l1){
                x = l1->val; 
                l1 = l1->next; 
            }
            if(l2){
                y = l2->val;
                l2 = l2->next;  
            }
            p = x + y + c; 

            ListNode *temp = new ListNode(); 
            res->val = p%10 ;
            if(l1 || l2 || p>=10){
                res->next = temp; 
            }else{
                break; 
            }
            res = temp; 
            if(p >= 10){
                c =1; 
            }else{
                c= 0 ; 
            }
        }   
        return head; 
    }
};