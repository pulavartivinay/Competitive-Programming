Question Link: https://leetcode.com/problems/number-of-islands/

Solution:

void DFS(int i,int j,vector<vector<char>>& matrix,int n,int m)
{
    if(i<0 or i>=n or j<0 or j>=m) return;
    if(matrix[i][j] == '0') return; 

    matrix[i][j] = '0';
    DFS(i-1,j,matrix,n,m); // up
    DFS(i+1,j,matrix,n,m); // down
    DFS(i,j+1,matrix,n,m); // right
    DFS(i,j-1,matrix,n,m); // left
}
int numIslands(vector<vector<char>>& matrix) 
{
    int m = matrix.size();
    int n = matrix[0].size();
    int ans = 0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j] == '1')
            {
                ans++;
                DFS(i,j,matrix,m,n);
            }
        }
    }
    return ans;
}
