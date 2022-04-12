Question Link: https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1#

Solution:

int isNegativeWeightCycle(int n, vector<vector<int>>edges){
    // Code here
      vector<int> store(n,INT_MAX);
      store[0] = 0;
      for(int v=0;v<(n-1);v++)
      {
          for(int i=0;i<edges.size();i++)
          {
              int u = edges[i][0];
              int v = edges[i][1];
              int w = edges[i][2];
              if(store[u] != INT_MAX && store[v] > store[u] + w) store[v] = store[u] + w;
          }
      }

      //detect if there is a negative weight cycle present in the directed graph
      for(int i=0;i<edges.size();i++)
      {
          int u = edges[i][0];
          int v = edges[i][1];
          int w = edges[i][2];
          if(store[u] != INT_MAX && store[v] > store[u] + w) return 1;
      }
    return 0;
}
