Question Link: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#


Solution Link: 

void InOrder(Node* root, vector<int>& leaves)
{
    if(root)
    {
        InOrder(root->left, leaves);
        if(root->left == NULL && root->right == NULL) leaves.push_back(root->data);
        InOrder(root->right, leaves);
    }
}
vector <int> printBoundary(Node *root)
{
    //Your code here
    vector<int> ans;
    ans.push_back(root->data);
    // 1.left nodes
    Node* travel = root->left;
    while(travel)
    {
        if(travel->left)
        {
            ans.push_back(travel->data);
            travel = travel->left;
        }
        else if(travel->right)
        {
            ans.push_back(travel->data);
            travel = travel->right;
        }
        else
        {
            break;
        }
    }
    // 2. all leaves
    vector<int> leaves;
    InOrder(root, leaves);
    for(int i=0;i<leaves.size();i++)
    {
        ans.push_back(leaves[i]);
    }
    // 3. right nodes
    vector<int> li;
    travel = root->right;
    while(travel)
    {
        if(travel->right)
        {
            li.push_back(travel->data);
            travel = travel->right;
        }
        else if(travel->left)
        {
            li.push_back(travel->data);
            travel = travel->left;
        }
        else
        {
            break;
        }
    }
    reverse(li.begin(), li.end());
    for(int i=0;i<li.size();i++)
    {
        ans.push_back(li[i]);
    }
    return ans;
}
