Question Link: https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

Solution:
void findPathHelper(int i, int j, string s, vector<vector<int>> &m, int n, vector<string> &ans, vector<vector<bool>> visited)
{
    if(i == n-1 && j == n-1)
    {
        ans.push_back(s);
        return;
    }
    
    // up
    if(i-1>=0 && visited[i-1][j] == false && m[i-1][j] == 1) 
    {
        visited[i-1][j] = true;
        findPathHelper(i-1, j, s+"U", m, n, ans, visited);
        visited[i-1][j] = false;
    }
    
    // down
    if(i+1<n && visited[i+1][j] == false && m[i+1][j] == 1) 
    {
        visited[i+1][j] = true;
        findPathHelper(i+1, j, s+"D", m, n, ans, visited);
        visited[i+1][j] = false;
    }
    
    // left
    if(j-1>=0 && visited[i][j-1] == false && m[i][j-1] == 1) 
    {
        visited[i][j-1] = true;
        findPathHelper(i, j-1, s+"L", m, n, ans, visited);
        visited[i][j-1] = false;
    }
    
    // right
    if(j+1<n && visited[i][j+1] == false && m[i][j+1] == 1) 
    {
        visited[i][j+1] = true;
        findPathHelper(i, j+1, s+"R", m, n, ans, visited);
        visited[i][j+1] = false;
    }

}
vector<string> findPath(vector<vector<int>> &m, int n) {
    // Your code goes here
    vector<string> ans;
    // source or destination is blocked
    if(m[0][0] == 0 || m[n-1][n-1] == 0) return ans;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string s = "";
    visited[0][0] = true;
    findPathHelper(0, 0, s, m, n, ans, visited);
    return ans;
}
