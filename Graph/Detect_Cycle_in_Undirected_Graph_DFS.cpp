Question Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

Solution:
bool detectCycle(int src, int par, vector<vector<int>>& adj, vector<int>& vis)
{
    vis[src] = true;

    for(int v:adj[src])
    {
        if(v != par)
        {
            if(vis[v]) return true;
            vis[v] = true;
            if(detectCycle(v, src, adj, vis)) return true;
        }
    }
    
    return false;
}
bool isCycle(int V, vector<vector<int>>& edges) {
    // Code here
    vector<int> vis(V, false);
    vector<vector<int>> adj(V);
    int u, v;
    for(int i=0;i<edges.size();i++)
    {
        u = edges[i][0], v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=0;i<V;i++)
    {
        if(!vis[i] && detectCycle(i, -1, adj, vis)) return true;
    }
    
    return false;
}
