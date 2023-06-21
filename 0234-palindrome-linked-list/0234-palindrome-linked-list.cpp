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
    ListNode *nhead;  
    bool ok = 0 ;
    ListNode* recur(ListNode* curr){
        if(!curr ){
            return NULL; 
        }
        
        ListNode* res =recur(curr->next);
        if(res){
            
        if(nhead->val != res->val ){
            ok =1 ; 
        }
        
        nhead = nhead->next; 
        }
        return curr ; 
    }
    bool isPalindrome(ListNode* head) {
        nhead = head; 
        recur(head); 
        return !ok; 
    }
};