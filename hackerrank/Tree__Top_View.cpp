/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

void left(node *root)
{
    if(root!=NULL)
    {
        left(root->left);
        printf("%d ", root->data);
    }
}

void right(node *root)
{
    if(root!=NULL)
    {
        printf("%d ", root->data);
        right(root->right);
    }
}

void topView(node * root)
{
    if( root!=NULL)
    {
        left(root->left);
        printf("%d ", root->data);
        right(root->right);
    }

}
