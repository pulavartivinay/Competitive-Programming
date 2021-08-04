Question Link: https://practice.geeksforgeeks.org/problems/sequence-of-sequence1155/1#

Solution:

void DFS(int i,int& temp,int& count,vector<int>& vis,int n,int m)
{
    if(i<=0 or i>m) return;
    if(vis[i]) return;
    if(temp > n) return;

    vis[i] = 1;
    temp++;
    if(temp == n) count++;
    for(int j=2*i;j<=m;j++)
    {
        DFS(j,temp,count,vis,n,m);
    }
    temp--;
    vis[i] = 0;
}
int numberSequence(int m, int n)
{
    // code here
    int ans = 0;
    vector<int> vis(m+1,0);
    for(int i=1;i<=m;i++)
    {
        int temp = 0;
        int count = 0;
        DFS(i,temp,count,vis,n,m);
        ans += count;
    }
    return ans;
}
