Question Link: https://www.naukri.com/code360/problems/1062626?topList=striver-sde-sheet-problems&leftPanelTabValue=PROBLEM

Solution:
bool DFS(int src,vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& path)
{
  visited[src] = true;
  path[src] = true;

  bool cycle = false;
  for(int i=0;i<adj[src].size();i++)
  {
    if(!visited[adj[src][i]]) 
    {
      cycle = DFS(adj[src][i], adj, visited, path);
      if(cycle) return cycle;
    }
    else if(path[adj[src][i]] == true) return true; 
  }

  path[src] = false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges)
 {
  // Write your code here.
  int m = edges.size();
  vector<vector<int>> adj(n);
  for(int i=0;i<m;i++)
  {
    int u = edges[i].first, v = edges[i].second;
    adj[u-1].push_back(v-1);
  }

  vector<bool> visited(n, false);
  vector<bool> path(n, false);
  bool cycle = false;
  for(int i=0;i<n;i++)
  {
    if(!visited[i]) cycle = DFS(i, adj, visited, path);
    if(cycle) return 1;
  }

  return 0;
}
