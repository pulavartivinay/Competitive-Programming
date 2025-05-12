Question Link: https://leetcode.com/problems/count-the-number-of-complete-components/description/

Solution:
void DFS(int src, vector<vector<int>>& adj, vector<bool>& vis, int& a, int& b)
{
    vis[src] = true;
    a++;
    b += adj[src].size();

    for(auto v:adj[src])
    {
        if(!vis[v]) DFS(v, adj, vis, a, b);
    }

    return;
}
int countCompleteComponents(int n, vector<vector<int>>& edges) {
    int e = edges.size();
    int cnt = 0, u, v;
    vector<vector<int>> adj(n);
    vector<bool> vis(n, false);

    // adjacency list
    for(int i=0;i<e;i++)
    {
        u = edges[i][0], v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int a, b;
    for(int i=0;i<n;i++)
    {
        a = 0, b = 0;
        if(!vis[i])
        {
            DFS(i, adj, vis, a, b);
            if(b == (a*(a-1))) cnt++;
        }
    }

    return cnt;
}
