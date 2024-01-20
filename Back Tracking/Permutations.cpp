Question Link: https://leetcode.com/problems/permutations/description/

Solution:
void helper(vector<int> curr, vector<bool> visited, vector<int>& nums, vector<vector<int>>& ans)
{
    if(curr.size() == nums.size())
    {
        ans.push_back(curr);
        return;
    }

    for(int i=0;i<nums.size();i++)
    {
        if(visited[i] == true) continue;
        curr.push_back(nums[i]);
        visited[i] = true;
        helper(curr, visited, nums, ans);
        visited[i] = false;
        curr.pop_back();
    }
    return;
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;

    long long int n = nums.size();

    vector<bool> visited(n, false);
    vector<int> curr;
    helper(curr, visited, nums, ans);

    return ans;
}
