Question Link: https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

Solution:

long long findMinDiff(vector<long long> a, long long n, long long m)
{
    //code
    long long int ans = INT_MAX;
    sort(a.begin(), a.end());
    for(int i=0;i<n;i++)
    {
        if(i+m-1 < n)
        {
            ans = min(ans, a[i+m-1] - a[i]);
        }
    }
    return ans;
}
