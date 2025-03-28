Question Link: https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/description/

Solution:
struct comp1
{
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        return (p1.first > p2.first);
    }
};
vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
    int r = grid.size(), c = grid[0].size();
    int q = queries.size();
    vector<int> ans(q, 0);

    auto comp2 = [&grid](pair<int, int> p1, pair<int, int> p2)
    {
        return (grid[p1.first][p1.second] > grid[p2.first][p2.second]);
    };

    priority_queue<pair<int, int>, vector<pair<int,int>>, comp1> pq1;
    priority_queue<pair<int, int>, vector<pair<int,int>>, decltype(comp2)> pq2(comp2);
    vector<vector<bool>> vis(r+1, vector<bool>(c+1, false));
    int cnt = 0;

    for(int i=0;i<q;i++) pq1.push({queries[i], i});
    pq2.push({0, 0});
    vis[0][0] = true;

    while(!pq1.empty())
    {
        pair<int, int> p = pq1.top();
        int val = p.first, ind = p.second;
        pq1.pop();

        // BFS on val using min-heap (priority_queue)
        while(!pq2.empty() && grid[pq2.top().first][pq2.top().second] < val)
        {
            pair<int, int> p2 = pq2.top();
            int i = p2.first, j = p2.second;
            pq2.pop();

            cnt++;

            // up
            if(i-1 >= 0 && !vis[i-1][j])
            {
                pq2.push({i-1, j});
                vis[i-1][j] = true;
            }

            // down
            if(i+1 < r && !vis[i+1][j])
            {
                pq2.push({i+1, j});
                vis[i+1][j] = true;
            }

            // left
            if(j-1 >= 0 && !vis[i][j-1])
            {
                pq2.push({i, j-1});
                vis[i][j-1] = true;
            }

            // right
            if(j+1 < c && !vis[i][j+1])
            {
                pq2.push({i, j+1});
                vis[i][j+1] = true;
            }
        }

        ans[ind] = cnt;
    }

    return ans;
}
