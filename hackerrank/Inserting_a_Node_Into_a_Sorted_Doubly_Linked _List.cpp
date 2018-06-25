/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* SortedInsert(Node *head, int data)
{
    // Complete this function
    // Do not write the main method.

    Node *node = NULL;
    Node *prv = NULL;
    Node *now = head;

    node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;

    if( head == NULL )
    {
        return node;
    }

    while( now != NULL && data > now->data )
    {
        prv = now;
        now = now->next;
    }

    if( prv == NULL ) // smaller than head
    {
        head->prev = node;
        node->next = head;
        head = node;
    }
    else if( now == NULL ) // larger than tail
    {
        prv->next = node;
        node->prev = prv;
    }
    else
    {
        node->prev = prv;
        node->next = now;

        prv->next = node;
        now->prev = node;
    }

    return head;
}
