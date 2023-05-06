Question Link: https://leetcode.com/problems/combination-sum/description/

Solution:

void helper(int i, int n, int s, vector<int> curr, 
            vector<vector<int>>& ans, vector<int>& candidates, int target)
{
    if(i == n) return;
    if(s > target) return;

    if(s == target) ans.push_back(curr);

    for(int j=i;j<n;j++)
    {
        curr.push_back(candidates[j]);
        helper(j, n, s + candidates[j], curr, ans, candidates, target);
        curr.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    int n = candidates.size();
    int s = 0;
    for(int i=0;i<n;i++)
    {
        vector<int> curr;
        s  = candidates[i];
        curr.push_back(candidates[i]);
        helper(i, n, s, curr, ans, candidates, target);
    }
    return ans;
}
