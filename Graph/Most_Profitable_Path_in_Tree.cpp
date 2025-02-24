Question Link: https://leetcode.com/problems/most-profitable-path-in-a-tree/description/

Solution:
bool findbobpath(int src, int dest, int time, vector<int>& visited,
                     vector<int>& bobpath, vector<vector<int>>& adj)
{
    visited[src] = true;
    bobpath[src] = time;

    if(src == dest) return true;

    bool found = false;
    for(auto v:adj[src])
    {
        if(!visited[v]) found = findbobpath(v, dest, time+1, visited, bobpath, adj);
        if(found) return found;
    }

    bobpath[src] = -1;
    return false;
}
int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
    int n = amount.size(), m = edges.size();
    vector<vector<int>> adj(n);
    vector<int> visited(n, false), bobpath(n, -1);

    int u,v;
    for(int i=0;i<m;i++)
    {
        u = edges[i][0];
        v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    // DFS
    findbobpath(bob, 0, 0, visited, bobpath, adj);
    
    for(int i=0;i<n;i++) visited[i] = false;;

    // BFS
    int ans = INT_MIN;
    queue<vector<int>> q;
    q.push({0, 0, 0});

    while(!q.empty())
    {
        vector<int> v = q.front();
        q.pop();
        int u = v[0];
        int time = v[1];
        int curr = v[2];
        
        visited[u] = true;

        if(bobpath[u] == -1 || time < bobpath[u]) curr += amount[u];
        else if(time == bobpath[u]) curr += (amount[u] / 2);

        if(adj[u].size() == 1 && u != 0) ans = max(ans, curr);

        for(auto v:adj[u])
        {
            if(!visited[v]) q.push({v, time+1, curr});
        }
    }

    return ans;
}
