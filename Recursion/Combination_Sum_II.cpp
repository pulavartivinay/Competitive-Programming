Question Link: https://leetcode.com/problems/combination-sum-ii/description/

Solution:
void helper(int k, int s, vector<int> curr, vector<int>& candidates, vector<vector<int>>& ans, int& target)
{
    if(s > target) return;
    else if(s == target)
    {
        ans.push_back(curr);
        return;
    }

    if(k == candidates.size()) return;

    for(int j=k;j<candidates.size();j++)
    {
        if(j > k && candidates[j] == candidates[j-1]) continue;
        curr.push_back(candidates[j]);
        helper(j+1, s + candidates[j], curr, candidates, ans, target);
        curr.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> curr;
    int s = 0;
    helper(0, s, curr, candidates, ans, target);

    return ans;
}
