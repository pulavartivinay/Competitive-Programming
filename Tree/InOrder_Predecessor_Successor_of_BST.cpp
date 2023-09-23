Question Link: https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1

Solution:
Node* InOrderPredecessor(Node* root, int key)
{
    if(root)
    {
        if(key <= root->key) return InOrderPredecessor(root->left, key);
        else return (InOrderPredecessor(root->right, key) ? InOrderPredecessor(root->right, key) : root);
    }
    return NULL;
}
Node* InOrderSuccessor(Node* root, int key)
{
    if(root)
    {
        if(key >= root->key) return InOrderSuccessor(root->right, key);
        else return (InOrderSuccessor(root->left, key) ? InOrderSuccessor(root->left, key) : root);
    }
    return NULL;
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    // Your code goes here
    pre = InOrderPredecessor(root, key);
    suc = InOrderSuccessor(root, key);
}
