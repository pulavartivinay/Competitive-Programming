Question Link: https://practice.geeksforgeeks.org/problems/inorder-traversal-iterative/1

Solution:

vector<int> inOrder(Node* root)
{
    //code here
    vector<int> ans;
    stack<Node*> s;
    Node* travel = root;
    s.push(root);
    while(!s.empty())
    {
        if(travel)
        {
            travel = travel->left;
            if(travel) s.push(travel);
        }
        else
        {
            ans.push_back(s.top()->data);
            Node* hi = s.top();
            s.pop();
            travel = hi->right;
            if(travel) s.push(travel);
        }
    }
    return ans;
}
