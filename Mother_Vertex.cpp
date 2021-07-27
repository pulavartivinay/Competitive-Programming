Question Link: https://practice.geeksforgeeks.org/problems/mother-vertex/1

Solution:

void DFS(int src, vector<bool>& visited, vector<int> adj[])
  {
      visited[src] = 1;
      for(int i=0;i<adj[src].size();i++)
      {
          if(!visited[adj[src][i]]) DFS(adj[src][i], visited, adj);
      }
  }
int findMotherVertex(int V, vector<int>adj[])
{
    // Code here
    for(int i=0;i<V;i++)
    {
        vector<bool> visited(V,0);
        DFS(i, visited, adj);
        int count = 0;
        for(int j=0;j<V;j++)
        {
            if(visited[j] == 1) count++;
        }
        if(count == V) return i;
    }
    return -1;
}
