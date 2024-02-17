Question Link: https://leetcode.com/problems/rotting-oranges/description/

Solution:
int orangesRotting(vector<vector<int>>& grid) {
    int ans = 0;
    int m = grid.size();
    int n = grid[0].size();

    queue<vector<int>> q;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j] == 2) q.push({i,j,0});
        }
    }

    while(!q.empty())
    {
        vector<int> v = q.front();
        q.pop();

        int i = v[0], j = v[1], mins = v[2];
        ans = max(ans, mins);

        // up
        if(i-1 >= 0 && grid[i-1][j] == 1)
        {
            grid[i-1][j] = 2;
            q.push({i-1, j, mins+1});
        }

        // down
        if(i+1 < m && grid[i+1][j] == 1)
        {
            grid[i+1][j] = 2;
            q.push({i+1, j, mins+1});
        }

        // left
        if(j-1 >= 0 && grid[i][j-1] == 1)
        {
            grid[i][j-1] = 2;
            q.push({i, j-1, mins+1});
        }

        // right
        if(j+1 < n && grid[i][j+1] == 1)
        {
            grid[i][j+1] = 2;
            q.push({i, j+1, mins+1});
        }
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j] == 1) return -1;
        }
    }

    return ans;
}
