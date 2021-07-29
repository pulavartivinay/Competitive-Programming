Question Link: https://leetcode.com/problems/subsets/submissions/

Solution:

void DFS(int i,vector<int> curr,int n,vector<int> nums,vector<bool>& vis,vector<vector<int>>& ans)
{
    if(i<0 or i>=n) return;
    if(vis[i]) return;

    vis[i] = 1;
    curr.push_back(nums[i]);
    ans.push_back(curr);
    for(int j=i+1;j<n;j++)
    {
        DFS(j,curr,n,nums,vis,ans); // right
    }
    vis[i] = 0;
}
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    ans.push_back({});
    for(int i=0;i<n;i++)
    {
        vector<int> curr;
        vector<bool> vis(n,0);
        DFS(i,curr,n,nums,vis,ans);
    }
    return ans;
}
