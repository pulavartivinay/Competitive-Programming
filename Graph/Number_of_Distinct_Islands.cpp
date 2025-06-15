Question Link: https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

Solution:
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    bool isValid(int i, int j, int n, int m)
    {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        set<vector<pair<int, int>>> st;
        queue<pair<int, int>> q;
        
        // Do BFS for all components
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]) continue;
                if(grid[i][j])
                {
                    vector<pair<int, int>> comp;
                    pair<int, int> base{i, j};
                    // BFS
                    q.push({i, j});
                    comp.push_back({i - base.first, j - base.second});
                    vis[i][j] = true;
                    
                    while(!q.empty())
                    {
                        pair<int, int> p = q.front();
                        q.pop();
                        int x = p.first, y = p.second;
                        
                        for(int d=0;d<4;d++)
                        {
                            int dir_x = x + dirs[d][0];
                            int dir_y = y + dirs[d][1];
                            
                            if(!isValid(dir_x, dir_y, n, m)) continue;
                            if(grid[dir_x][dir_y] == 0) continue;
                            if(vis[dir_x][dir_y]) continue;
                            
                            q.push({dir_x, dir_y});
                            comp.push_back({dir_x - base.first, dir_y - base.second});
                            vis[dir_x][dir_y] = true;
                        }
                    }
                    st.insert(comp);
                }
            }
        }
        
        return st.size();
    }
};
