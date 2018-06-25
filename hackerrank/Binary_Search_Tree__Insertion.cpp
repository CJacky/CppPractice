/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/

node * insert(node * root, int value)
{
    node *now = root;

    if( root == NULL )
    {
        root = (node*)malloc(sizeof(node));
        root->data = value;
        root->left = NULL;
        root->right= NULL;
        return root;
    }

    while(1)
    {
        if( value > now->data )
        {
            if( now->right == NULL )
            {
                now->right = (node*)malloc(sizeof(node));
                now->right->data = value;
                now->right->left = NULL;
                now->right->right= NULL;
                break;
            }
            else
            {
                now = now->right;
            }
        }
        else if( value < now->data )
        {
            if( now->left == NULL )
            {
                now->left = (node*)malloc(sizeof(node));
                now->left->data = value;
                now->left->left = NULL;
                now->left->right= NULL;
                break;
            }
            else
            {
                now = now->left;
            }
        }
    }
    
   return root;
}
