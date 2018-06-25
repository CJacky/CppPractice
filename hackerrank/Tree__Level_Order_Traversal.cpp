
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

#define MAX_LEVEL           8192
#define MAX_LEN_PER_LEVEL   512

static int level[MAX_LEVEL][MAX_LEN_PER_LEVEL];

void preOrder(node* root, int lv)
{
    if( root != NULL )
    {
        level[lv][ ++level[lv][0] ] = root->data;
        preOrder(root->left,  lv+1);
        preOrder(root->right, lv+1);
    }
}

void levelOrder(node * root)
{  
    memset(level, 0, sizeof(level));
  
    preOrder(root, 0);
    
    for(int i=0; i<MAX_LEVEL; ++i)
    {
        for(int j=1; j<=level[i][0]; ++j)
        {
            printf("%d ", level[i][j]);
        }
    }
}
