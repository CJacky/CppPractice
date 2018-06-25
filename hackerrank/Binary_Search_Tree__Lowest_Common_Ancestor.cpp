/*
Node is defined as 

typedef struct node
{
   int data;
   node *left;
   node *right;
}node;

*/

bool cmp(int a, int b, int c)
{
    if( a<b && b<c )
    {
        return true;
    }
    return false;
}


node *lca(node *root, int v1, int v2)
{
    node *cur = root;
     
    if( v2 < v1 )
    {
        int tmp = v1;
        v1 = v2;
        v2 = tmp;
    }
    
    while( cur != NULL )
    {
        if( cur->data == v1 || cur->data == v2 || cmp(v1, cur->data, v2) == true )
        {
            return cur;
        }
        
        if( cmp(v1, v2, cur->data) == true )
        {
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }
    }
    return cur;
}

