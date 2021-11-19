Question Link: https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1

Solution:

void DFS(int sr,int sc,vector<vector<int>>& image,int n,int m,int curr_color,int newColor,vector<vector<bool>>& vis)
{
    if(sr<0 or sc<0 or sr>=n or sc>=m) return;
    if(vis[sr][sc]) return;
    if(image[sr][sc] != curr_color) return;

    vis[sr][sc] = 1;
    image[sr][sc] = newColor;
    DFS(sr-1,sc,image,n,m,curr_color,newColor,vis); // up
    DFS(sr+1,sc,image,n,m,curr_color,newColor,vis); // down
    DFS(sr,sc-1,image,n,m,curr_color,newColor,vis); // left
    DFS(sr,sc+1,image,n,m,curr_color,newColor,vis); // right
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    // Code here
    int n = image.size();
    int m = image[0].size();
    int curr_color = image[sr][sc];
    vector<vector<bool>> vis(n, vector<bool>(m));
    DFS(sr,sc,image,n,m,curr_color,newColor,vis);
    return image;
}
