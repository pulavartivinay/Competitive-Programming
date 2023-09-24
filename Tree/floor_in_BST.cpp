Question Link: https://www.codingninjas.com/studio/problems/floor-from-bst_920457?source=youtube&campaign=Striver_Tree_Videos&leftPanelTab=0

Solution:
int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    if(root)
    {
        if(X < root->val) return floorInBST(root->left, X);
        else {
          int store = floorInBST(root->right, X);
          return ((store != -1) ? store : root->val);
        }
    }
    return -1;
}
