Question Link: https://www.naukri.com/code360/problems/1062670?topList=striver-sde-sheet-problems

Solution:
bool DFS(int src, int par, vector<vector<int>>& adj, vector<bool>& visited)
{
    visited[src] = true;

    for(int i=0;i<adj[src].size();i++)
    {
        bool cycle = false;
        if(!visited[adj[src][i]]) 
        {
            cycle = DFS(adj[src][i], src, adj, visited);
            if(cycle) return true;
        }
        else if(par == adj[src][i]) continue;
        else return true;
    }

    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++)
    {
        int u = edges[i][0], v = edges[i][1];
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vector<bool> visited(n, false);
    for(int i=0;i<n;i++)
    {
        bool cycle = false;
        if(!visited[i]) cycle = DFS(i, -1, adj, visited);
        if(cycle) return "Yes";
    }

    return "No";
}
