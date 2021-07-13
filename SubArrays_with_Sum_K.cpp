Question Link: https://practice.geeksforgeeks.org/problems/subarrays-with-sum-k/1

Solution:

int findSubArraySum(int Arr[], int N, int k)
{
    // code here
    unordered_map<int, int> m;
    m[0] = 1;
    int ans = 0;
    int sum = 0;
    for(int i=0;i<N;i++)
    {
        sum += Arr[i];
        if(m[sum - k] > 0) ans += m[sum - k];
        m[sum]++;
    }
    return ans;
}
