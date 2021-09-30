Question Link: https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1/


Solution Link:

static bool comp(vector<int> a, vector<int> b)
{
    return (a[0] < b[0]);
}
vector<int> verticalOrder(Node *root)
{
    //Your code here
    vector<vector<int>> v;
    queue<pair<Node*,vector<int>>> q;
    int dist = 1000;
    q.push({root,{dist, root->data}});
    while(!q.empty())
    {
        auto d = q.front();
        q.pop();
        Node* j = d.first;
        if(j->left) q.push({j->left,{d.second[0] - 1, j->left->data}});
        if(j->right) q.push({j->right,{d.second[0] + 1, j->right->data}});

        v.push_back(d.second);
    }
    stable_sort(v.begin(), v.end(), comp);
    vector<int> ans;
    for(int i=0;i<v.size();i++)
    {
        ans.push_back(v[i][1]);
    }
    return ans;
}
