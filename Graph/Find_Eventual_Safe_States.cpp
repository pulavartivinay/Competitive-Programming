Question Link: https://leetcode.com/problems/find-eventual-safe-states/

Solution:
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      // reverse the given graph
      // find indegree zero nodes (initial terminal nodes)
      // nodes     ->  0 1 2 3 4 5 6
      // indegree  ->  2 2 1 1 1 0 0
      // terminal nodes --> 5 6
      // 2 2 0 1 0 0 0 --> 5 6 4 2
      // 1 1 0 1 0 0 0 --> 5 6 4 2 (iteration completed)

      int n = graph.size();
      vector<int> ans;
      vector<vector<int>> g(n);
      vector<int> inDegree(n);
      queue<int> q;

      for(int i=0;i<n;i++)
      {
          for(int j=0;j<graph[i].size();j++)
          {
              int u = i, v = graph[i][j];
              g[v].push_back(u);
              inDegree[u]++;
          }
      }

      // terminal nodes
      for(int i=0;i<n;i++)
      {
          if(inDegree[i] == 0) q.push(i);
      }

      // BFS
      while(!q.empty())
      {
          int curr = q.front();
          q.pop();

          // push the curr node to ans (all safe nodes)
          ans.push_back(curr);

          for(auto v:g[curr])
          {
              inDegree[v]--;
              if(inDegree[v] == 0) q.push(v);
          }
      }

      sort(ans.begin(), ans.end());
      return ans;
  }
