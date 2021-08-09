Question Link: https://practice.geeksforgeeks.org/problems/find-sum-of-different-corresponding-bits-for-all-pairs4652/1

Solution:

int countBits(int N, long long int A[])
{
    // code here
    long long int mod = pow(10,9)+7;
    int ans = 0;
    for(int i=0;i<32;i++)
    {
        long long int count_set_bits = 0;
        for(int j=0;j<N;j++)
        {
            if(A[j] & (1 << i)) count_set_bits++;
        }
        ans = (ans + (count_set_bits)*(N - count_set_bits)*2)%mod;
    }
    return ans;
}
