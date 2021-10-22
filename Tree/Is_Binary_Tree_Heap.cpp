Question Link: https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1

Solution:

int totalNodes(struct Node* tree)
{
    if (tree == NULL) return (0);
    return (1 + totalNodes(tree->left) + totalNodes(tree->right));
}

bool isComplete(struct Node* tree, int index, int number_nodes)
{
    if (tree == NULL) return true;

    if (index >= number_nodes) return false;

    return (isComplete(tree->left, 2*index + 1, number_nodes) & isComplete(tree->right, 2*index + 2, number_nodes));
}
bool isHeapHelper(Node* tree, int a)
{
    if(a <= tree->data) return false; 
    if(tree->left == NULL && tree->right == NULL) return true;
    else if(tree->left && tree->right == NULL) return isHeapHelper(tree->left, tree->data);
    else if(tree->left == NULL && tree->right) return isHeapHelper(tree->right, tree->data);
    else if(tree->left && tree->right) return (isHeapHelper(tree->left, tree->data) & isHeapHelper(tree->right, tree->data));
    return true;
}
bool isHeap(struct Node* tree) 
{
    // code here
    int t = totalNodes(tree);
    if(!isComplete(tree,0,t)) return false;
    if(tree->left == NULL && tree->right == NULL) return true;
    else if(tree->left && tree->right == NULL) return isHeapHelper(tree->left, tree->data);
    else if(tree->left == NULL && tree->right) return isHeapHelper(tree->right, tree->data);
    else if(tree->left && tree->right) return (isHeapHelper(tree->left, tree->data) & isHeapHelper(tree->right, tree->data));
    return true;
}
