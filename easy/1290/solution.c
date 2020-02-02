/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <math.h>
int gPower = 0;
int sumOfChild(struct ListNode* root) {
    int tmpSum = 0, selfSum = 0;
    if (root->next == NULL) {
        gPower++;
        return root->val;
    }
    tmpSum = sumOfChild(root->next);
    selfSum = root->val*pow(2, gPower);
    gPower++;
    return tmpSum + selfSum;
}

int getDecimalValue(struct ListNode* head){
    int result = sumOfChild(head);
    gPower = 0;
    return result;
}
