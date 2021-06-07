Question Link: https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1

Solution Link: 

Node* minValueTree(Node* root)
{
    Node* current = root;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}
Node *deleteNode(Node *root,  int X)
{
    // your code goes here
    if(root)
    {
        if(root->data == X)
        {
            if(root->left == NULL && root->right == NULL)
            {
                return NULL;
            }
            else if(root->left == NULL && root->right != NULL)
            {
                return root->right;
            }
            else if(root->left != NULL && root->right == NULL)
            {
                return root->left;
            }
            else
            {
                Node* minNode = minValueTree(root->right);
                root->data = minNode->data;
                root->right = deleteNode(root->right, minNode->data);
            }
        }
        else if(root->data > X)
        {
            root->right = deleteNode(root->right, X);
        }
        else if(root->data < X)
        {
            root->left = deleteNode(root->left, X);
        }
        return root;
    }
    else
    {
        return NULL;
    }
}
