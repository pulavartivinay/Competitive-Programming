Question Link: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

Solution:

void DFS(int x, int y, string curr, vector<vector<int>> &m, int n, vector<vector<int>>& visited,vector<string>& ans)
{
  visited[x][y] = 1;
  if(x == n-1 && y == n-1 && m[x][y] == 1)
  {
      ans.push_back(curr);
  }
  else
  {
      if(x+1 <= n-1 && m[x+1][y] == 1 && visited[x+1][y] == 0) //down
      {
          DFS(x+1,y,curr + "D",m,n,visited,ans);
          visited[x+1][y] = 0;
      }
      if(0 <= y-1 && m[x][y-1] == 1 && visited[x][y-1] == 0) //left
      {
          DFS(x,y-1,curr + "L",m,n,visited,ans);
          visited[x][y-1] = 0;
      }
      if(y+1 <= n-1 && m[x][y+1] == 1 && visited[x][y+1] == 0) //right
      {
          DFS(x,y+1,curr + "R",m,n,visited,ans);
          visited[x][y+1] = 0;
      }
      if(0 <= x-1 && m[x-1][y] == 1 && visited[x-1][y] == 0) //up
      {
          DFS(x-1,y,curr + "U",m,n,visited,ans);
          visited[x-1][y] = 0;
      }
  }
}
vector<string> findPath(vector<vector<int>> &m, int n) {
    // Your code goes here
    vector<string> ans;
    vector<vector<int>> visited (n, vector<int> (n,0));
    if(m[0][0] == 0) return ans;
    DFS(0,0,"",m,n,visited,ans);
    return ans;
}
