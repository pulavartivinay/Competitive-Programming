Question Link: https://leetcode.com/problems/count-primes/description/

Solution:
int countPrimes(int n) {
    if (n == 0 | n == 1) return 0;
    int ans = 0;
    // mark all numbers as prime
    vector<int> arr(n+1,1);
    // 0 and 1 are not primes
    arr[0] = 0;
    arr[1] = 0;
    for(int i=2;i<n;i++)
    {
        if(arr[i])
        {
            ans++;
            for(int j=2*i;j<n;j=j+i)
            {
                // j is a multiple of i, mark as not prime
                arr[j] = 0;
            }
        }
    }
    return ans;
}
