Question Link: https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1

Solution:
int checkIsBalanced(Node* root)
{
    if(!root) return 0;
    
    int l = checkIsBalanced(root->left);
    if(l == -1) return -1;
    
    int r = checkIsBalanced(root->right);
    if(r == -1) return -1;
    
    if(abs(l-r) > 1) return -1;
    else return (max(l,r)+1);
}
bool isBalanced(Node *root)
{
    //  Your Code here
    if(!root) return true;
    if(checkIsBalanced(root) >= 0) return true;
    else return false;
}
