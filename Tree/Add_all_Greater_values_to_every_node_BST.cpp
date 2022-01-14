Question Link: https://practice.geeksforgeeks.org/problems/add-all-greater-values-to-every-node-in-a-bst/1

Solution:

void reverseInOrder(Node* root, int& ans)
{
    if(root)
    {
        reverseInOrder(root->right, ans);
        root->data += ans;
        ans = root->data;
        reverseInOrder(root->left, ans);
    }
}
Node* modify(Node *root)
{
    // Your code here
    int ans = 0;
    reverseInOrder(root, ans);
    return root;
}
