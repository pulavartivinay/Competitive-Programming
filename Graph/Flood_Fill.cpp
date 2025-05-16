Question Link: https://leetcode.com/problems/flood-fill/description/

Solution:
bool isValid(int r, int c, vector<vector<int>>& image)
{
    int n = image.size(), m = image[0].size();
    return (r >= 0 && r < n && c >= 0 && c < m);
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int n = image.size(), m = image[0].size(), x, y;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    queue<pair<int, int>> q;
    int orig_color = image[sr][sc];
    if(orig_color == color) return image;
    image[sr][sc] = color;
    q.push({sr, sc});

    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        x = p.first, y = p.second;

        for(int i=0;i<4;i++)
        {
            int d_x = x + dirs[i][0], d_y = y + dirs[i][1];
            if(isValid(d_x, d_y, image) && image[d_x][d_y] == orig_color)
            {
                image[d_x][d_y] = color;
                q.push({d_x, d_y});
            } 
        }
    }

    return image;
}
