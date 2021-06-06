Question Link: https://practice.geeksforgeeks.org/problems/construct-tree-from-preorder-traversal/1#

Solution Link: 

struct Node* newNode (int data)
{
    struct Node *temp = new struct Node(data);
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* helper(int pre[], char preLN[], int* index_ptr, int n)
{
    int pointing = (*index_ptr);
    Node* li = newNode(pre[pointing]);
    (*index_ptr)++;
    if(preLN[pointing] == 'N')
    {
        li->left = helper(pre, preLN, index_ptr, n);
        li->right = helper(pre, preLN, index_ptr, n);
    }
    return li;
}
struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
    int index = 0;
    return helper(pre, preLN, &index, n);
}
