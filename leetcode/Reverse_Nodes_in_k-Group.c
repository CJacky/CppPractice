/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include "common.h"

#ifdef MY_DEBUG
#define msg(fmt, args...)   printf(fmt, ##args)
#else
#define msg(fmt, args...)
#endif // MY_DEBUG

static void revert(struct ListNode* s, struct ListNode* e, int k)
{
    struct ListNode *p = NULL, *n;

    for( int i=0; i<k; ++i )
    {
        msg("s=%d\n", s->val);
        n = s->next;
        s->next = p;
        p = s;
        s = n;
    }
}

struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
    int c = 0;
    struct ListNode *h, *e, *ph, *ret;

    if( head == NULL )
    {
        return NULL;
    }

    if( k == 1 )
    {
        return head;
    }

    ret = head;
    h = e = ph = NULL;

    while( head != NULL )
    {
        if( c == 0 )
        {
           h = head;
           msg("h=%d\n", h->val);
           head = head->next;
        }
        else if( c == k-1 )
        {
            e = head;
            msg("e=%d\n", e->val);
            head = head->next;

            revert(h, e, k);

            if( ph == NULL )
            {
                ret = e;
                msg("ret=%d\n", ret->val);
            }
            else
            {
                ph->next = e;
            }
            h->next = head;
            ph = h;
        }
        else
        {
            head = head->next;
        }
        msg("\n");
        c = (c+1)%k;
    }

    return ret;
}
