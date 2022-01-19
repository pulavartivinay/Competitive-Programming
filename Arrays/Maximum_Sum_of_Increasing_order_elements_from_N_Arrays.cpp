Question Link: https://practice.geeksforgeeks.org/problems/maximum-sum-of-increasing-order-elements-from-n-arrays4848/1#

Solution:

int maximumSum( int n,int m, vector<vector<int>> &a) 
{

    // Complete the function
    int ans = 0;
    int mx = INT_MAX;
    for(int i=n-1;i>=0;i--)
    {
        int temp = INT_MIN;
        for(int j=0;j<m;j++)
        {
            if(a[i][j] < mx) temp = max(temp, a[i][j]);
        }
        if(temp == INT_MIN) return 0;
        mx = temp;
        ans += mx;
    }
    return ans;
}
