Question Link: https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

Solution:
void inorderReverse(Node* root, int&K, int& ans)
{
    if(root)
    {
        inorderReverse(root->right, K, ans);
        if(K == 1)
        {
            ans = root->data;
            K--;
            return;
        }
        K--;
        inorderReverse(root->left, K, ans);
    }
    return;
}

int kthLargest(Node *root, int K)
{
    //Your code here
    if(root)
    {
        int ans = -1;
        inorderReverse(root, K, ans);
        return ans;
    }
    return -1;
}
