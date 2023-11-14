Question: https://leetcode.com/problems/subsets-ii/description/

Solution:
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    ans.push_back({});
    int start = 0, end = 0;

    for(int i=0;i<nums.size();i++)
    {
        int n = ans.size();

        // duplicate case handle
        if(i > 0 && nums[i] == nums[i-1]) start = end+1;
        else start = 0;

        end = ans.size()-1;

        for(int j=start;j<=end;j++)
        {
            vector<int> t = ans[j];
            t.push_back(nums[i]);
            ans.push_back(t);
        }
    }

    return ans;
}
