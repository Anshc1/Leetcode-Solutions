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
    ListNode* prev = NULL;
    ListNode* nxtp = NULL;
    ListNode* head; 
    int mx ;
   
    ListNode* recur(ListNode * curr  ,  int ct  ,  int k   ) {
        if (ct == mx) {
            prev = curr;
            return NULL;
        }
        if (curr->next == NULL ) {
            nxtp = curr; 
            return curr;
        }
        ListNode* res = recur(curr->next, ct + 1 ,  k );
        //cout<< ct <<endl; ; 
        if(res){
           // cout<<"-->>"<<res->val <<endl; 
        }
        if (res) {
            if (ct % k == 1) {
                res->next = curr ;
                curr->next = prev;
                prev = nxtp;
            } else if (ct % k == 0 ) {
                //cout<<"---->>>>"<<ct<<endl; 
                nxtp = curr;
            } else {
                res ->next = curr;
            }
            return curr;
        } 
        if(ct%k == 0 ){
            nxtp= curr; 
        }
        return curr;
    

    }
    ListNode* reverseKGroup(ListNode* head1, int k) {
        head =head1; 
        ListNode* curr = head ;
        ListNode* start = head ;
        int sz = 0 ;
        if(k ==1){
            return head1; 
        }
        while (start) {
            sz++;
            start = start->next;
        }
        
        mx = 1e6;
        if (sz % k != 0 ) {
            int f = sz / k ;
            f *= k ;
            mx = f + 1;
        }
        //cout<<mx<<endl; 
        
        recur(curr , 1 , k);
        return nxtp ; 
    }
};