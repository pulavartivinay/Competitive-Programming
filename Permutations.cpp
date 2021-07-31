Question Link: https://leetcode.com/problems/permutations/

Solution:

void DFS(int i,vector<vector<int>>& ans,vector<int> temp,int n,vector<bool>& vis,vector<int>& nums,int count)
{
    if(i<0 or i>n) return;
    if(vis[i]) return;

    vis[i] = 1;
    temp.push_back(nums[i]);
    if(count == n-1) ans.push_back(temp);
    for(int j=0;j<n;j++)
    {
        if(i != j)
        {
            DFS(j,ans,temp,n,vis,nums,count+1);
        }
    }
    vis[i] = 0;
}
vector<vector<int>> permute(vector<int>& nums) 
{
    vector<vector<int>> ans;
    int n = nums.size();
    for(int i=0;i<n;i++)
    {
        vector<bool> vis(n,0);
        vector<int> temp;
        int count = 0;
        DFS(i,ans,temp,n,vis,nums,count);
    }
    return ans;
}
