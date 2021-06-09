Question Link: https://practice.geeksforgeeks.org/problems/unique-bsts-1587115621/1

Solution Link:

int numTrees(int N) 
    {
        // Your code here
        long long int mod = 1000000007;
        vector<long long int> arr (N+1,0);
        arr[0] = 1;
        arr[1] = 1;
        for(int i=2;i<=N;i++) //calculating the previous values
        {
            for(int j=1;j<=i;j++) //iterating all possible root values and counting them
            {
                arr[i] = (arr[i] + (arr[j-1]*arr[i-j]))%mod;
            }
        }
        return arr[N]%mod;
    }
