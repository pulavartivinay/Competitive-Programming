Question Link: https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1

Solution:
Node* LCA(Node *root, int n1, int n2)
{
    // code here
    int a = min(n1, n2);
    int b = max(n1, n2);
    if(root->data == a || root->data == b) return root;
    else if(a < root->data && root->data < b) return root;
    else if(a < root->data && b < root->data) return LCA(root->left, a, b);
    else return LCA(root->right, a, b);
}
