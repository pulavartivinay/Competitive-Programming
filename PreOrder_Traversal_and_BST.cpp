Question Link: https://practice.geeksforgeeks.org/problems/preorder-traversal-and-bst4006/1

Solution:

int BST_Helper(int arr[], int N, int start, int end, int low_limit, int high_limit)
{
    if(start <= end)
    {
        int root = arr[start];
        if(low_limit <= root && root <= high_limit)
        {
            int h = -1;
            for(int i=start+1;i<=end;i++)
            {
                if(arr[i] > root)
                {
                    h = i;
                    break;
                }
            }
            if(h != -1) return (BST_Helper(arr, N, start+1, h-1, low_limit, root) & BST_Helper(arr, N, h, end, root, high_limit));
            else return (BST_Helper(arr, N, start+1, end, low_limit, root));
        }
        else return 0;
    }
    else return 1;
}
int canRepresentBST(int arr[], int N) {
    // code here
    int low_limit = 1;
    int high_limit = INT_MAX;
    return BST_Helper(arr, N, 0, N-1, low_limit, high_limit);
}
