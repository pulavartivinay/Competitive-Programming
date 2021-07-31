Question Link: https://leetcode.com/problems/subsets-ii/

Solution:

void DFS(int i,set<vector<int>>& s,vector<int> temp,int n,vector<bool>& vis,vector<int> nums)
{
    if(i<0 or i>=n) return;
    if(vis[i]) return;

    vis[i] = 1;
    temp.push_back(nums[i]);
    s.insert(temp);
    for(int j=i+1;j<n;j++)
    {
        DFS(j,s,temp,n,vis,nums);
    }
    vis[i] = 0;
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) 
{
    sort(nums.begin(),nums.end());
    set< vector<int> > s;
    int n = nums.size();
    for(int i=0;i<n;i++)
    {
        vector<bool> vis(n,0);
        vector<int> temp;
        DFS(i,s,temp,n,vis,nums);
    }
    vector< vector<int>> ans (s.begin(),s.end());
    ans.push_back({});
    return ans;
}
