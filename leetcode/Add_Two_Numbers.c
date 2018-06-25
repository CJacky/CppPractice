/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include "common.h"

#ifdef MY_DEBUG
#define msg(fmt, args...) printf(fmt, ##args)
#else
#define msg(fmt, args...)
#endif // MY_DEBUG

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *l3 = NULL, *tmp = NULL;
    int a, b, c = 0;

    while (l1 != NULL || l2 != NULL)
    {
        a = b = 0;
        if (l1 != NULL)
        {
            a = l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            b = l2->val;
            l2 = l2->next;
        }
        c = a + b + c;

        if (l3 == NULL)
        {
            l3 = malloc(sizeof(struct ListNode));
            l3->next = NULL;
            l3->val = c % 10;
            c = c / 10;
            tmp = l3;
        }
        else
        {
            tmp->next = malloc(sizeof(struct ListNode));
            tmp->next->val = c % 10;
            c = c / 10;
            tmp->next->next = NULL;
            tmp = tmp->next;
        }
    }

    if (c > 0)
    {
        tmp->next = malloc(sizeof(struct ListNode));
        tmp->next->val = c;
        tmp->next->next = NULL;
    }

    return l3;
}
