Question Link: https://practice.geeksforgeeks.org/problems/check-for-bst/1

Solution:

bool checkBST(Node* root,int l,int h)
{
    if(root)
    {
        if(l < root->data && root->data < h)
        {
            bool a = checkBST(root->left,l,min(root->data,h));
            bool b = checkBST(root->right,max(root->data,l),h);comp
            return (a & b);
        }
        else return false;
    }
    else return true;
}
bool isBST(Node* root) 
{
    // Your code here
    int l = INT_MIN;
    int h = INT_MAX;
    return checkBST(root,l,h);
}
