Question Link: https://practice.geeksforgeeks.org/problems/check-for-bst/1/?company[]=Amazon&company[]=Amazon&problemType=functional&page=1&sortBy=submissions&query=company[]AmazonproblemTypefunctionalpage1sortBysubmissionscompany[]Amazon

Solution:

void InOrder(Node* root, vector<int>& li)
{
    if(root)
    {
        InOrder(root->left, li);
        li.push_back(root->data);
        InOrder(root->right, li);
    }
}
bool isBST(Node* root) 
{
    // Your code here
    vector<int> li;
    InOrder(root, li);
    int n = li.size();
    for(int i=0;i<(n-1);i++)
    {
        if(li[i] >= li[i+1])
        {
            return 0;
        }
    }
    return 1;
}
