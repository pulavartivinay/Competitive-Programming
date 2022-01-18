Question Link: https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

Solution:

pair<int,int> PostOrder(Node* root)
{
    if(root)
    {
        pair<int,int> p1 = PostOrder(root->left);
        pair<int,int> p2 = PostOrder(root->right);
        int a = p1.first;
        int b = p1.second;
        int c = p2.first;
        int d = p2.second;
        // first value when it is included and second value when it is not included
        return {b + root->data + d, max( b + d, max( max(a + max(c,d), b + c), max(c + max(a,b), d + a) ) ) };
    }
    else return {0,0};
}
//Function to return the maximum sum of non-adjacent nodes.
int getMaxSum(Node *root) 
{
    // Add your code here
    pair<int,int> p = PostOrder(root);
    return max(p.first, p.second);
}
