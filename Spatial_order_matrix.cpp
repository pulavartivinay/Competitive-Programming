Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order
Input Format:
The first and the only argument contains an integer, A.
Output Format:
Return a 2-d matrix of size A x A satisfying the spiral order.
Constraints:
1 <= A <= 1000
Examples:
Input 1:
    A = 3
Output 1:
    [   [ 1, 2, 3 ],
        [ 8, 9, 4 ],
        [ 7, 6, 5 ]   ]
Input 2:
    4
Output 2:
    [   [1, 2, 3, 4],
        [12, 13, 14, 5],
        [11, 16, 15, 6],
        [10, 9, 8, 7]   ]
       
Solution:
  vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int> > b( A , vector<int> (A, 0));
    int count=0;
    int value = 1;
    int m = A;
    int n = A;
    int k,l = 0;
    while(k < m and l < n)
    {
        for(int i=l;i<n;i++)
        {
            b[k][i] = value;
            value = value + 1;
        }
        k = k + 1;
        for(int i=k;i<m;i++)
        {
            b[i][n-1] = value;
            value = value + 1;
        }
        n = n - 1;
        if(k < m)
        {
            for(int i=n-1;i>=l;i--)
            {
                b[m-1][i] = value;
                value = value + 1;
            }
        }
        m = m - 1;
        if(l < n)
        {
            for(int i=m-1;i>=k;i--)
            {
                b[i][l] = value;
                value = value+1;
            }
        }
        l = l + 1;
    }
    return b;
}
