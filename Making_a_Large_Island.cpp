Question Link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/613/week-1-august-1st-august-7th/3835/

Solution:

void DFS(int i,int j,vector<vector<int>>& matrix,vector<vector<bool>>& vis,vector<vector<int>>& id,int n,int& count,int islands)
{
    if(i<0 or i>=n or j<0 or j>=n) return;
    if(vis[i][j]) return;
    if(matrix[i][j] == 0) return;

    vis[i][j] = 1;
    id[i][j] = islands;
    count++;
    DFS(i-1,j,matrix,vis,id,n,count,islands); // up
    DFS(i+1,j,matrix,vis,id,n,count,islands); // down
    DFS(i,j+1,matrix,vis,id,n,count,islands); // right
    DFS(i,j-1,matrix,vis,id,n,count,islands); // left
}
int largestIsland(vector<vector<int>>& matrix) 
{
    int n = matrix.size();
    int ans = 0;
    vector<vector<int>> id(n,vector<int>(n));
    int islands = 1;
    unordered_map<int,int> m;
    vector<vector<bool>> vis(n,vector<bool>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j] == 1 && vis[i][j] == 0)
            {
                int count = 0;
                DFS(i,j,matrix,vis,id,n,count,islands);
                ans = max(ans,count);
                m[islands] = count;
                // cout << m[islands] << endl;
                islands++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j] == 0)
            {
                unordered_set<int> s;
                if(i-1>=0 && matrix[i-1][j])
                {
                    s.insert(id[i-1][j]);
                }
                if(i+1<n && matrix[i+1][j])
                {
                    s.insert(id[i+1][j]);
                }
                if(j-1>=0 && matrix[i][j-1])
                {
                    s.insert(id[i][j-1]);
                }
                if(j+1<n && matrix[i][j+1])
                {
                    s.insert(id[i][j+1]);
                }
                int temp = 1;
                for(auto kl:s)
                {
                    // cout << kl << endl;
                    temp += m[kl];
                }
                ans = max(ans,temp);
            }
        }
    }
    return ans;
}
