/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode tmp;
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *current = &tmp;
    struct ListNode *l1_cur = l1;
    struct ListNode *l2_cur = l2;
    struct ListNode *last = NULL;
    struct ListNode *greater;
    int carry = 0;

    do {
        current->val = l1_cur->val + l2_cur->val + carry;
        if (current->val > 9) {
            carry = 1;
            current->val -= 10;
        }
        else {
            carry = 0;
        }
        current->next = malloc(sizeof(struct ListNode));
        last = current;
        current = current->next;
        l1_cur = l1_cur->next;
        l2_cur = l2_cur->next;
    } while(l1_cur != NULL && l2_cur != NULL);

    // check which node is greater
    if (l1_cur == NULL && l2_cur == NULL) {
        greater = NULL;
    }
    else if (l1_cur == NULL) {
        greater = l2_cur;
    }
    else {
        greater = l1_cur;
    }

    if (greater == NULL) {
        if (carry == 0) {
            free(current);
            last->next = NULL;
            return &tmp;
        }
        else {
            current->val = 1;
            current->next = NULL;
            return &tmp;
        }
    }
    while (greater != NULL) {
        current->val = greater->val + carry;
        if (current->val > 9) {
            carry = 1;
            current->val -= 10;
        }
        else {
            carry = 0;
        }
        current->next = malloc(sizeof(struct ListNode));
        last = current;
        current = current->next;
        greater = greater->next;
    }
    if (carry == 1) {
        current->val = 1;
        current->next = NULL;
    }
    else {
        free(current);
        last->next = NULL;
    }

    return &tmp;
}
