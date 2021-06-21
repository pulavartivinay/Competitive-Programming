Question Link: https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

Solution:

//Function to find number of strongly connected components in the graph.
	void DFS(int& i, vector<int> adj[], vector<int>& visited, stack<int>& s)
	{
	    visited[i] = 1;
	    for(int j=0;j<(adj[i].size());j++)
	    {
	        if(visited[adj[i][j]] == 0)
	        {
	            DFS(adj[i][j], adj, visited, s);
	        }
	    }
	    s.push(i);
  }
  int kosaraju(int V, vector<int> adj[])
  {
      //code here
      //Step-1: Create an Empty Stack
      stack<int> s;
      //Step-2: Call DFS on given graph with source vertex as "0"
      vector<int> visited (V,0);
      for(int i=0;i<V;i++)
      {
          if(visited[i] == 0)
          {
              DFS(i, adj, visited, s);
          }
      }
      //Step-3: Transpose the Graph G and make all the vertices unvisited
      vector<int> adjT[V];
      for(int i=0;i<V;i++)
      {
          visited[i] = 0;
          for(int j=0;j<(adj[i].size());j++)
          {
              adjT[adj[i][j]].push_back(i);
          }
      }
      //Step-4: Call DFS on the Transpose Graph until all the vertices are visited 
      stack<int> temp_s;
      int count = 0;
      while(!s.empty())
      {
          int top_ele = s.top();
          if(visited[top_ele] == 0)
          {
              visited[top_ele] = 1;
              DFS(top_ele, adjT, visited, temp_s);
              count = count + 1;
          }
          else
          {
              s.pop();
          }
      }
      return count;
  }
