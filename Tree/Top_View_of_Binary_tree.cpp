Question Link: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

Solution:

vector<int> topView(Node *root)
{
    //Your code here
    vector<int> ans;
    if(root == NULL) return ans;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    map<int,int> m;
    while(!q.empty())
    {
        auto p = q.front();
        q.pop();
        Node* t = p.first;
        int d = p.second;
        if(m.count(d) == 0) m[d] = t->data;
        if(t->left) q.push({t->left, d-1});
        if(t->right) q.push({t->right, d+1});
    }
    for(auto k:m)
    {
        ans.push_back(k.second);
    }
    return ans;
}
