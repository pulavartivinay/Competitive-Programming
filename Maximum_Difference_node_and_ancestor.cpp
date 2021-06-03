Question Link: https://practice.geeksforgeeks.org/problems/maximum-difference-between-node-and-its-ancestor/1/

Solution Link: 

int LowestValue(Node* root, int& ans)
{
    if(root)
    {
        int lowestLeft = INT_MAX;
        int lowestRight = INT_MAX;
        if(root->left)
        {
            lowestLeft = LowestValue(root->left, ans);
        }
        if(root->right)
        {
            lowestRight = LowestValue(root->right, ans);
        }
        if(root->left == NULL && root->right == NULL)
        {
            return root->data;
        }
        int temp_max = max((root->data)-lowestLeft, (root->data)-lowestRight);
        ans = max(ans, temp_max);
        int temp_min = min(lowestLeft, lowestRight);
        return min(root->data, temp_min);
    }
}
//Function to return the maximum difference between any node and its ancestor.
int maxDiff(Node* root)
{
    // Your code here 
    int ans = INT_MIN;
    int gh = LowestValue(root, ans);
    return ans;
}
