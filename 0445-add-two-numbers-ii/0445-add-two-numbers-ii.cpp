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
    int comp_s(ListNode* head){
        int sz = 0; 
        ListNode* curr = head ; 
        while(curr != NULL){
            curr= curr->next; 
            sz++; 
        }
        return sz ; 
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n = comp_s(l1); 
        int m = comp_s(l2); 
        if(n < m ){
            swap(n , m ); 
            swap(l1 , l2); 
        }
        ListNode *curr = l1 ;
        stack<ListNode*>x , y;
        while(l1){
            x.push(l1); 
            l1 =l1->next; 
        }
        while(l2){
            y.push(l2); 
            l2= l2->next; 
        }
        int carry =0; 
        while(!x.empty() ){
            auto p = x.top();
            x.pop(); 
            auto q = 0  ; 
            if(!y.empty()){
                q =y.top()->val;
                y.pop(); 
            }
            int r = p->val + q + carry; 
            p->val = r % 10 ;
            carry = r/10; 
        }
        if(carry >0 ){
            ListNode* N= new ListNode();
            N ->next = curr ;
            N->val = carry; 
            return N ; 
        }
        return curr; 
    }
};