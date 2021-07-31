Question Link: https://leetcode.com/problems/combinations/

Solution:

void DFS(int i,int n,vector<vector<int>>& ans,vector<int> temp,int count,int k,vector<bool>& vis)
{
    if(i<=0 or i>n) return;
    if(vis[i]) return;
    if(count > k) return;

    vis[i] = 1;
    temp.push_back(i);
    if(count == k) ans.push_back(temp);
    for(int j=i+1;j<=n;j++)
    {
        DFS(j,n,ans,temp,count+1,k,vis);
    }
    vis[i] = 0;
}
vector<vector<int>> combine(int n, int k) 
{
    vector<vector<int>> ans;
    for(int i=1;i<=n;i++)
    {
        vector<bool> vis(n+1,0);
        vector<int> temp;
        int count = 0;
        DFS(i,n,ans,temp,count+1,k,vis);
    }
    return ans;
}
