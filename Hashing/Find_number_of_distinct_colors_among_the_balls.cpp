Question Link: https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/description/

Solution:
vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    int n = queries.size();
    vector<int> ans(n);

    unordered_map<int, int> mp, color;
    int cnt = 0, x, y;
    vector<int> q;
    for(int i=0;i<n;i++)
    {
        q = queries[i];
        x = q[0], y = q[1];

        // delete op
        if(color[x] != 0)
        {
            mp[color[x]]--;
            if(mp[color[x]] == 0) cnt--;
        }

        // add op
        color[x] = y;
        mp[y]++;
        if(mp[y] == 1) cnt++;

        ans[i] = cnt;
    }

    return ans;
}
