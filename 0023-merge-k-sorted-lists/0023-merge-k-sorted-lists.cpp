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
    ListNode* insertNode(ListNode* n1 , ListNode* n2 ){
        if(n1 == NULL){
            return n2 ; 
        }
        if(n2 == NULL){
            return n1; 
        }
        if(n1->val <= n2->val){
            n1->next = insertNode(n1->next , n2); 
            return n1; 
        }else{
            n2->next = insertNode(n1 , n2->next); 
            return n2; 
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return NULL; 
        }
        while(lists.size() > 1){
            auto l1= lists[0]; 
            auto l2= lists[1]; 
            lists.push_back(insertNode(l1, l2)); 
            lists.erase(lists.begin()); 
            lists.erase(lists.begin()); 
        }
        return lists[0]; 
    }
};