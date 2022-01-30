Question Link: https://practice.geeksforgeeks.org/problems/257a9e27fb3e58255622c8dcb06e0919cc1c6c11/1#

Solution:

int Maximum_Sum(vector<vector<int>> &mat,int N,int K)
{
    // Your code goes here
    int ans = INT_MIN;
    //store all the sums in a 2D vector
    vector<vector<int>> st(N, vector<int>(N,0));
    int col_sum = 0;
    for(int i=0;i<N;i++)
    {
        col_sum = 0;
        for(int j=0;j<N;j++)
        {
            col_sum += mat[j][i];
            st[j][i] = col_sum;
        }
    }
    // row and column wise window sliding
    for(int l=0;l<=(N-K);l++)
    {
        int t = 0;
        for(int b=l;b<(l+K);b++)
        {
            t += st[K-1][b];
        }
        // cout << "First: t " << t << endl;
        ans = max(ans, t);
        for(int i=K;i<N;i++)
        {
            t = 0;
            for(int j=l;j<(l+K);j++)
            {
                t += st[i][j] - st[i-K][j];
            }
            // cout << "Second: t " << t << endl;
            ans = max(ans,t);
        }
    }
    return ans;
}
