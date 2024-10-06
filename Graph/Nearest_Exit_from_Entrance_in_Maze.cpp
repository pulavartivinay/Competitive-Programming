Question Link: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/?envType=study-plan-v2&envId=leetcode-75

Solution:
bool isExit(int i, int j, int n, int m, vector<int>& entrance)
{
    if((i != entrance[0] || j != entrance[1]) 
            && (i == 0 || j == 0 || i == n-1 || j == m-1)) return true;
    
    return false;
}
int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int n = maze.size(); // rows
    int m = maze[0].size(); //cols

    int ans = INT_MAX;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<vector<int>> q;
    q.push({entrance[0], entrance[1], 0});
    visited[entrance[0]][entrance[1]] = true;

    while(!q.empty())
    {
        vector<int> curr = q.front();
        q.pop();

        int i = curr[0], j = curr[1], dis = curr[2];
        if(isExit(i, j, n, m, entrance))
        {
            ans = min(ans, dis);
            continue;
        }

        // top
        if(i-1 >= 0 && maze[i-1][j] != '+' && !visited[i-1][j])
        {
            q.push({i-1, j, dis+1});
            visited[i-1][j] = true;
        }

        // down
        if(i+1 < n && maze[i+1][j] != '+' && !visited[i+1][j])
        {
            q.push({i+1, j, dis+1});
            visited[i+1][j] = true;
        }

        // left
        if(j-1 >= 0 && maze[i][j-1] != '+' && !visited[i][j-1])
        {
            q.push({i, j-1, dis+1});
            visited[i][j-1] = true;
        }

        // right
        if(j+1 < m && maze[i][j+1] != '+' && !visited[i][j+1])
        {
            q.push({i, j+1, dis+1});
            visited[i][j+1] = true;
        }
    }

    return (ans == INT_MAX) ? -1 : ans;
}
