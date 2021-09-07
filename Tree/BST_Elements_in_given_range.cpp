Question Link: https://practice.geeksforgeeks.org/problems/print-bst-elements-in-given-range/1

Solution:

void InOrder(Node* root,vector<int>& ans,int low,int high)
 {
    if(root)
    {
        InOrder(root->left,ans,low,high);
        if(low<=root->data && root->data<=high) ans.push_back(root->data);
        InOrder(root->right,ans,low,high);
    }
}
vector<int> printNearNodes(Node *root, int low, int high) 
{
    //code here   
    vector<int> ans;
    InOrder(root,ans,low,high);
    return ans;
}
