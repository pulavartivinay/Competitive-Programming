Question Link: https://www.hackerrank.com/contests/logicmojo-feb23/challenges/binary-search-tree-lowest-common-ancestor/problem

Solution:
Node *lca(Node *root, int v1,int v2) 
{
    // Write your code here.
    if(!root) return root;
    int a = min(v1, v2);
    int b = max(v1, v2);
    if(a < root->data && root->data < b) return root;
    else if(a < root->data && b < root->data) return lca(root->left, v1, v2);
    else if(a > root->data && b > root->data) return lca(root->right, v1, v2);
    return root;
}
