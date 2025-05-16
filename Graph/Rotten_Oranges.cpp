Question Link: https://leetcode.com/problems/rotting-oranges/description/

Solution:
int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int cnt = 0;
    queue<vector<int>> q;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j] == 2) q.push({i, j});
        }
    }

    int size = 0;
    while(!q.empty())
    {
        size = q.size();
        while(size--)
        {
            vector<int> v = q.front();
            q.pop();
            int i = v[0], j = v[1];

            // top
            if(i-1 >= 0 && grid[i-1][j] == 1)
            {
                grid[i-1][j] = 2;
                q.push({i-1, j});
            }

            // bottom
            if(i+1 < n && grid[i+1][j] == 1)
            {
                grid[i+1][j] = 2;
                q.push({i+1, j});
            }

            // left
            if(j-1 >= 0 && grid[i][j-1] == 1)
            {
                grid[i][j-1] = 2;
                q.push({i, j-1});
            }

            // right
            if(j+1 < m && grid[i][j+1] == 1)
            {
                grid[i][j+1] = 2;
                q.push({i, j+1});
            }
        }
        if(q.size() > 0) cnt++;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j] == 1) return -1;
        }
    }

    return cnt;
}
