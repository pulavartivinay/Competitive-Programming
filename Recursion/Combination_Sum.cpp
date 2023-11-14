Question Link: https://leetcode.com/problems/combination-sum/description/

Solution:
void helper(int k, int s, vector<int> curr, vector<vector<int>>& ans, vector<int>& candidates, int target)
{
    if(k == candidates.size()) return;
    if(s > target) return;

    if(s == target) 
    {
        ans.push_back(curr);
        return;
    }

    for(int j=k;j<candidates.size();j++)
    {
        curr.push_back(candidates[j]);
        helper(j, s + candidates[j], curr, ans, candidates, target);
        curr.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> curr;
    int s = 0;
    helper(0, s, curr, ans, candidates, target);
    return ans;
}
