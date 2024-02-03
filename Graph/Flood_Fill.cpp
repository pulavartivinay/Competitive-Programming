Question Link: https://leetcode.com/problems/flood-fill/description/

Solution:
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int m = image.size(); // rows
    int n = image[0].size(); // cols
    int src_col = image[sr][sc];
    queue<pair<int,int>> q;
    image[sr][sc] = color;
    q.push({sr, sc});
    while(!q.empty())
    {
        pair<int,int> p = q.front();
        int x = p.first;
        int y = p.second;
        
        q.pop();

        // up
        if(x-1 >= 0 && image[x-1][y] == src_col && src_col != color)
        {
            image[x-1][y] = color;
            q.push({x-1,y});
        }

        // down
        if(x+1 < m && image[x+1][y] == src_col && src_col != color)
        {
            image[x+1][y] = color;
            q.push({x+1,y});
        }

        // left
        if(y-1 >= 0 && image[x][y-1] == src_col && src_col != color)
        {
            image[x][y-1] = color;
            q.push({x,y-1});
        }

        // right
        if(y+1 < n && image[x][y+1] == src_col && src_col != color)
        {
            image[x][y+1] = color;
            q.push({x,y+1});
        }
    }
    
    return image;
}
