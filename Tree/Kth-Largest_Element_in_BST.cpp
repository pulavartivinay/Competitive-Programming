Question Link: https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

Solution:

void InOrder_ASC(Node* root, int& K, int& count, int& ans)
{
    if(root)
    {
        InOrder_ASC(root->right, K, count, ans);
        if(count == K)
        {
            ans = root->data;
            count = count + 1; // this is very important. if u miss this statement, then it will always returns the root value. think about it.
            return;
        }
        else
        {
            count = count + 1;
        }
        InOrder_ASC(root->left, K, count, ans);
    }
}
int kthLargest(Node *root, int K)
{
    //Your code here
    int count = 1;
    int ans = 0;
    InOrder_ASC(root, K, count, ans);
    return ans;
}
