Question Link: https://leetcode.com/problems/surrounded-regions/description/

Solution:
class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool isValid(int i, int j, int n, int m)
    {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        // top
        for(int j=0;j<m;j++)
        {
            if(board[0][j] == 'O') q.push({0, j});
            vis[0][j] = true;
        }

        // bottom
        for(int j=0;j<m;j++)
        {
            if(vis[n-1][j]) continue;
            if(board[n-1][j] == 'O') q.push({n-1, j});
            vis[n-1][j] = true;
        }

        // left
        for(int i=0;i<n;i++)
        {
            if(vis[i][0]) continue;
            if(board[i][0] == 'O') q.push({i, 0});
            vis[i][0] = true;
        }

        // bottom
        for(int i=0;i<n;i++)
        {
            if(vis[i][m-1]) continue;
            if(board[i][m-1] == 'O') q.push({i, m-1});
            vis[i][m-1] = true;
        }

        // BFS
        while(!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first, y = p.second;

            for(int i=0;i<4;i++)
            {
                int dir_x = x + dirs[i][0];
                int dir_y = y + dirs[i][1];

                if(!isValid(dir_x, dir_y, n, m)) continue;

                if(vis[dir_x][dir_y]) continue;

                if(board[dir_x][dir_y] == 'O')
                {
                    q.push({dir_x, dir_y});
                    vis[dir_x][dir_y] = true;
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j]) board[i][j] = 'X';
            }
        }

        return;
    }
};
