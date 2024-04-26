Question Link: https://leetcode.com/problems/number-of-islands/description/

Solution:
bool isValid(int r, int c, vector<vector<char>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();

    return (r >= 0 && r < n && c >= 0 && c < m);
}

void BFS(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited)
{
    queue<pair<int,int>> q;
    visited[i][j] = true;
    q.push({i, j});

    while(!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();
        int r = p.first;
        int c = p.second;

        // top
        if(isValid(r-1, c, grid) && grid[r-1][c] == '1' && !visited[r-1][c]) 
        {
            visited[r-1][c] = true;
            q.push({r-1, c});
        }

        // bottom
        if(isValid(r+1, c, grid) && grid[r+1][c] == '1' && !visited[r+1][c]) 
        {
            visited[r+1][c] = true;
            q.push({r+1, c});
        }

        // left
        if(isValid(r, c-1, grid) && grid[r][c-1] == '1' && !visited[r][c-1]) 
        {
            visited[r][c-1] = true;
            q.push({r, c-1});
        }

        // right
        if(isValid(r, c+1, grid) && grid[r][c+1] == '1' && !visited[r][c+1]) 
        {
            visited[r][c+1] = true;
            q.push({r, c+1});
        }
    }
}
int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j] == '1' && !visited[i][j]) 
            {
                BFS(i, j, grid, visited);
                ans++;
            }
        }
    }

    return ans;
}
