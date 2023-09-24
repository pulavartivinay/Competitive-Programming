Question Link: https://www.codingninjas.com/studio/problems/ceil-from-bst_920464?source=youtube&campaign=Striver_Tree_Videos&leftPanelTab=0

Solution:
int findCeil(BinaryTreeNode<int> *node, int x)
{
    // Write your code here.
    if(node)
    {
        if(x > node->data) return findCeil(node->right, x);
        else {
            int store = findCeil(node->left, x);
            return ((store != -1) ? store : node->data);
        }
    }
    return -1;
}
