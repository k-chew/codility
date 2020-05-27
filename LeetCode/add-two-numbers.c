/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *result = malloc(sizeof(struct ListNode));
    struct ListNode *resultPointer = result;
    int carry = 0;
    int sum;
    while (l1 && l2) {
        sum = l1->val + l2->val + carry;
        if (sum >= 10) {
            resultPointer->val = sum % 10;
            carry = 1;
        } else {
            resultPointer->val = sum;
            carry = 0;
        }
        l1 = l1->next;
        l2 = l2->next;
        resultPointer->next = malloc(sizeof(struct ListNode));
        resultPointer = resultPointer->next;
    }
    free(resultPointer);
    return result;
}
