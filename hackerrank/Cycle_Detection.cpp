/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) 
{
    Node *cur;
    Node *next;
    Node *tmp;
    if( head == NULL || head->next == NULL )
    {
        return false;
    }
    
    cur = head;
    next = head->next;
    while( 1 )
    {
        if( cur == NULL || next == NULL )
        {
            break;
        }
        tmp = next->next;
        next->next = cur;
        cur = next;
        next= tmp;
        if( cur == head )
        {
            return true;
        }
    }
    return false;
}
