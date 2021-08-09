Question Link: https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1

Solution:

void InOrder1(Node* root, unordered_map<int,int>& m)
{
    if(root)
    {
        InOrder1(root->left, m);
        m[root->data] = 1;
        InOrder1(root->right, m);
    }
}
void InOrder2(Node* root, unordered_map<int,int>& m, int& x, int& count)
{
    if(root)
    {
        InOrder2(root->left, m, x, count);
        if(m[x - root->data]) count = count + 1;
        InOrder2(root->right, m, x, count);
    }
}
int countPairs(Node* root1, Node* root2, int x)
{
    // Code here
    unordered_map<int,int> m;
    InOrder1(root1, m);
    int count = 0;
    InOrder2(root2, m, x, count);
    return count;
}
