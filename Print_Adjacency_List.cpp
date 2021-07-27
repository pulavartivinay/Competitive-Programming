Question Link: https://practice.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1

Solution:

vector<vector<int>>printGraph(int V, vector<int> adj[])
{
    // Code here
    vector<vector<int>> ans;
    for(int i=0;i<V;i++)
    {
        vector<int> temp;
        temp.push_back(i);
        for(int j=0;j<(adj[i].size());j++)
        {
            temp.push_back(adj[i][j]);
        }
        ans.push_back(temp);
    }
    return ans;
}
