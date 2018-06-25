
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root)
    {
        if(root == NULL)
        {
            return -1;
        }
        else
        {
            int L = height(root->left);
            int R = height(root->right);
            return (L>R)? L+1:R+1;
        }
    }
  