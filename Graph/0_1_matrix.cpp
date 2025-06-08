Question Link: https://leetcode.com/problems/01-matrix/

Solution:
class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool isValid(int i, int j, int n, int m)
    {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>> q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }

        while(!q.empty())
        {
            pair<pair<int, int>, int> v = q.front();
            q.pop();
            pair<int, int> p = v.first;
            int x = p.first, y = p.second, steps = v.second;

            for(int i=0;i<4;i++)
            {
                int dir_x = x + dirs[i][0];
                int dir_y = y + dirs[i][1];

                if(!isValid(dir_x, dir_y, n, m)) continue;

                if(vis[dir_x][dir_y]) continue;

                ans[dir_x][dir_y] = steps + 1;
                q.push({{dir_x, dir_y}, steps + 1});
                vis[dir_x][dir_y] = true;
            }
        }

        return ans;
    }
};
