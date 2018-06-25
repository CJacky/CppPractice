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

int node_min(struct ListNode** lists, int listsSize)
{       
    int min = -1;
    
    for(int i=0; i<listsSize; ++i)
    {
        msg("%d %p\n", i, lists[i]);
        if( lists[i] != NULL && (min == -1 || lists[i]->val < lists[min]->val) )
        {
            min = i;   
        }
    }
    return min;
}  

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    struct ListNode* tmp;
    int min;
        
    while((min = node_min(lists, listsSize)) != -1 )
    {
        msg("%d\n", min);
        tmp = lists[min];
        lists[min] = lists[min]->next;
        if( head == NULL && tail == NULL )
        {
            head = tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tmp;
        }
    }
    return head;
}






