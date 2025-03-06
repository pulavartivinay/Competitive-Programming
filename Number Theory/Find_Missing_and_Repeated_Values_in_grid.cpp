Question Link: https://leetcode.com/problems/find-missing-and-repeated-values/description/

Solution:
vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<int> ans(2);

    long long int sum = 0, sum2 = 0, actual_sum = 0, actual_sum2 = 0;
    long long int a = pow(n, 2);
    actual_sum = ((a * (a + 1))/2);
    actual_sum2 = ((a * (a + 1) * (2*a + 1))/6);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            sum += grid[i][j];
            sum2 += pow(grid[i][j], 2);
        }
    }
    long long int a_b = (sum - actual_sum);
    long long int a_plus_b = ((sum2 - actual_sum2)/(a_b));

    ans[0] = ((a_b + a_plus_b)/2);
    ans[1] = a_plus_b - ans[0];

    return ans;
}
