Question Link: https://practice.geeksforgeeks.org/problems/all-unique-permutations-of-an-array/1

Solution:

void DFS(int i,set<vector<int>>& s,vector<int> temp,int n,vector<bool>& vis,vector<int>& arr,int count)
{
    if(i<0 or i>n) return;
    if(vis[i]) return;

    vis[i] = 1;
    temp.push_back(arr[i]);
    if(count == n-1) s.insert(temp);
    for(int j=0;j<n;j++)
    {
        if(i != j)
        {
            DFS(j,s,temp,n,vis,arr,count+1);
        }
    }
    vis[i] = 0;
}
vector<vector<int>> uniquePerms(vector<int> arr ,int n) 
{
    // code here
    set<vector<int>> s;
    for(int i=0;i<n;i++)
    {
        vector<bool> vis(n,0);
        vector<int> temp;
        int count = 0;
        DFS(i,s,temp,n,vis,arr,count);
    }
    vector<vector<int>> ans (s.begin(), s.end());
    sort(ans.begin(), ans.end());
    return ans;
}
