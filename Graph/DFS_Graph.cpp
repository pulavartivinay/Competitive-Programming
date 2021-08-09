Question Link: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

Solution:

void DFS(int src, vector<bool>& visited, vector<int> adj[], vector<int>& ans)
{
    visited[src] = 1;
    ans.push_back(src);
    for(int i=0;i<adj[src].size();i++)
    {
        if(!visited[adj[src][i]]) DFS(adj[src][i], visited, adj, ans);
    }
}
vector<int>dfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<int> ans;
    vector<bool> visited(V,0);
    for(int i=0;i<V;i++)
    {
        if(!visited[i]) DFS(i, visited, adj, ans);
    }
    return ans;
}
