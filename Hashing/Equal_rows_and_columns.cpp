Question Link: https://leetcode.com/problems/equal-row-and-column-pairs/description/

Solution:
int equalPairs(vector<vector<int>>& grid) {
    int ans = 0;
    unordered_map<string, int> row_mp;

    int n = grid.size();
    string curr = "";
    for(int i=0;i<n;i++)
    {
        curr = "";
        for(int j=0;j<n;j++)
        {
            curr += to_string(grid[i][j]);
            curr += ",";
        }

        row_mp[curr]++;
    }

    for(int i=0;i<n;i++)
    {
        curr = "";
        for(int j=0;j<n;j++)
        {
            curr += to_string(grid[j][i]);
            curr += ",";
        }

        if(row_mp[curr] != 0) ans += row_mp[curr];
    }

    return ans;
}
