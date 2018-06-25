/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* Reverse(Node* head)
{
    Node *prev = NULL;
    Node *next = NULL;
    
    if( head == NULL )
    {
        return NULL;
    }
    
    prev = head->prev;
    next = head->next;
    
    head->next = prev;
    head->prev = next;
    
    if( next == NULL )        
    {
        return head;
    }
    else
    {
        return Reverse(next);
    }
}
