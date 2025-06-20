Question Link: https://leetcode.com/problems/course-schedule/description/

Solution:
void DFS(int src, vector<vector<int>>& adj, vector<bool>& vis,
            vector<bool>& path_vis, bool& cycle)
{
    if(cycle) return;

    vis[src] = true;
    path_vis[src] = true;

    for(int v:adj[src])
    {
        if(path_vis[v])
        {
            cycle = true;
            return;
        }
        if(vis[v]) continue;

        DFS(v, adj, vis, path_vis, cycle);
        if(cycle) return;
    }

    path_vis[src] = false;

    return;
}
bool canFinish(int n, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(n);

    for(int i=0;i<prerequisites.size();i++)
    {
        int u = prerequisites[i][0], v = prerequisites[i][1];
        adj[u].push_back(v);
    }
    vector<bool> vis(n, false), path_vis(n, false);
    bool cycle = false;

    for(int i=0;i<n;i++)
    {
        if(vis[i]) continue;
        DFS(i, adj, vis, path_vis, cycle);
        if(cycle) return false;
    }

    return true;
}
