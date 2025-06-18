Question Link: https://leetcode.com/problems/course-schedule-ii/description/

Solution:
void DFS(int src, int n, vector<vector<int>>& adj,
            vector<int>& vis, vector<int>& pathVis, bool& cycle, vector<int>& ans)
{
    vis[src] = true;
    pathVis[src] = true;

    for(int v:adj[src])
    {
        // cycle exists (not DAG)
        if(pathVis[v])
        {
            cycle = true;
            return;
        }
        if(vis[v]) continue;
        DFS(v, n, adj, vis, pathVis, cycle, ans);
        if(cycle) return;
    }

    cout << src << endl;
    ans.push_back(src);

    pathVis[src] = false;
    return;
}
vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(n);
    vector<int> ans;
    vector<int> vis(n, false), pathVis(n , false);
    bool cycle = false;

    for(int i=0;i<prerequisites.size();i++)
    {
        int u = prerequisites[i][0], v = prerequisites[i][1];
        adj[u].push_back(v);
    }

    for(int i=0;i<n;i++)
    {
        if(vis[i]) continue;
        DFS(i, n, adj, vis, pathVis, cycle, ans);
        if(cycle) return {};
    }

    return ans;
}
