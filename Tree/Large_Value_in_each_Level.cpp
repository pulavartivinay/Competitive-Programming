Question Link: https://practice.geeksforgeeks.org/problems/largest-value-in-each-level/1

Solution:

void PreOrder(Node* root, vector<int>& ans, int h)
{
    if(root)
    {
        if(ans.size() <= h) ans.push_back(root->data);
        else ans[h] = max(ans[h], root->data);
        PreOrder(root->left, ans, h+1);
        PreOrder(root->right, ans, h+1);
    }
}
vector<int> largestValues(Node* root)
{
    //code here
    vector<int> ans;
    PreOrder(root, ans, 0);
    return ans;
}
