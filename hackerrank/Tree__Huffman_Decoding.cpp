/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/


void decode_huff(node * root,string s)
{
    node *cur = root;
    int i;
    for(i=0; i<s.length(); ++i )
    {
        if( s[i] == '0' )
        {
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }

        if( cur->left == NULL && cur->right == NULL )    
        {
            printf("%c", cur->data);
            cur = root;
        }
            
    }
}
