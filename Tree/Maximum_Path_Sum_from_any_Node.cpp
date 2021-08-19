Question Link: https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1

Solution:

int helper(Node* root)
{
    if(root)
    {
        int a = helper(root->left);
        int b = helper(root->right);
        return max({root->data,root->data+a,root->data+b});
    }
    else return 0;
}

void InOrder(Node* root,int& ans)
{
    if(root)
    {
        InOrder(root->left,ans);
        int g = helper(root->left);
        int k = helper(root->right);
        ans = max({ans,root->data,root->data+g,root->data+k,g+root->data+k});
        InOrder(root->right,ans);
    }
}

//Function to return maximum path sum from any node in a tree.
int findMaxSum(Node* root)
{
    // Your code goes here
    int ans = INT_MIN;
    InOrder(root,ans);
    return ans;
}
