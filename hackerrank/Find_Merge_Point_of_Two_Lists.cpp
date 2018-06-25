/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
int FindMergeNode(Node *headA, Node *headB)
{
    Node *tmpA = headA;
    Node *tmpB;
    while( tmpA != NULL )
    {
        tmpB = headB;
        while(tmpB != NULL)
        {
            if( tmpA->data == tmpB->data )
            {
                return tmpA->data;
            }
            tmpB = tmpB->next;
        }
        tmpA = tmpA->next;
    }
    return 0;
}
