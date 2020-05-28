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
    while (1) {
        // it is possible that one number's digits are already added fully
        // so we must check before adding to this iteration's sum
        sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        if (sum >= 10) {
            resultPointer->val = sum % 10;
            carry = 1;
        } else {
            resultPointer->val = sum;
            carry = 0;
        }
        if (l1 || l2) {
          resultPointer->next = malloc(sizeof(struct ListNode));
          resultPointer = resultPointer->next;
        } else {
          if (carry == 1) {
            resultPointer->next = malloc(sizeof(struct ListNode));
            resultPointer->next->val = 1;
            resultPointer->next->next = NULL;
            break;
          }
          resultPointer->next = NULL;
          break;
        }
    }
    return result;
}
