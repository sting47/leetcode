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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* lo = NULL;
        ListNode* lout = NULL;
        if( l1 != NULL || l2 != NULL ) {
            lo = new ListNode(0);
            lout = lo;
        }
        else {
            return lout;
        }
        while( l1 != NULL && l2 != NULL ) {
            lo->next = new ListNode(0);
            if( l1->val < l2->val ) {
                lo->val = l1->val;
                l1 = l1->next;
            }
            else {
                lo->val = l2->val;
                l2 = l2->next;
            }
            lo = lo->next;
        }
        if( l1 != NULL ) {
            while( l1 != NULL ) {
                lo->val = l1->val;
                if( l1->next != NULL ){
                    lo->next = new ListNode(0);
                    lo = lo->next;
                }
                l1 = l1->next;
            }
        }
        if( l2 != NULL ) {
            while( l2 != NULL ) {
                lo->val = l2->val;
                if( l2->next != NULL ){
                    lo->next = new ListNode(0);
                    lo = lo->next;
                }
                l2 = l2->next;
            }
        }
        lo->next = NULL;
        return lout;
    }
};
