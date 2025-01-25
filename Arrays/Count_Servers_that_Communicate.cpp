Question Link: https://leetcode.com/problems/count-servers-that-communicate/description/

Solution:
int countServers(vector<vector<int>>& grid) {
    int ans = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<int> row_cnt(n, 0);
    vector<int> col_cnt(m, 0);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j] == 1)
            {
                ans++;
                row_cnt[i] += 1;
                col_cnt[j] += 1;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j] == 1 && row_cnt[i] == 1 && col_cnt[j] == 1) ans--;
        }
    }
    
    return ans;
}
