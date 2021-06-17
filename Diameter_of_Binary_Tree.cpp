Question Link: https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

Solution:

int calculateMaxNode(Node* root)
{
    if(root)
    {
        return 1 + max(calculateMaxNode(root->left), calculateMaxNode(root->right));
    }
    else
    {
        return 0;
    }
}
// Function to return the diameter of a Binary Tree.
int diameter(Node* root) {
    // Your code here
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    if(root)
    {
        if(root->left != NULL)
        {
            a = diameter(root->left);
        }
        if(root->right != NULL)
        {
            b = diameter(root->right);
        }
        c = calculateMaxNode(root->left);
        d = calculateMaxNode(root->right);
        return max(max(a,b),c+d+1);        
    }
}

