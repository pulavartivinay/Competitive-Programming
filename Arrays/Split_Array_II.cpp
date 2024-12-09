Question Link: https://leetcode.com/problems/special-array-ii/description/

Solution:
vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
    int q = queries.size();
    vector<bool> ans(q, false);

    int n = nums.size();
    vector<int> prefix(n, 0);
    for(int i=1;i<n;i++)
    {
        int sum = nums[i] + nums[i-1];
        if(sum & 1) prefix[i] = prefix[i-1];
        else prefix[i] = prefix[i-1] + 1;
    }

    for(int i=0;i<q;i++)
    {
        int left = queries[i][0], right = queries[i][1];
        ans[i] = (prefix[right] - prefix[left] == 0);
    }

    return ans;
}
