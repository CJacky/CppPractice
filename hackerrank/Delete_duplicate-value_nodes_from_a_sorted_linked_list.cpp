/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    Node *cur = head;
    Node *tmp = NULL;
     
    while( cur != NULL )
    {
        tmp = cur->next;
        while( tmp != NULL && tmp->data == cur->data )
        {
            tmp = tmp->next;
        }
        cur->next = tmp;
        cur = tmp;
    }
    
    return head;
}
