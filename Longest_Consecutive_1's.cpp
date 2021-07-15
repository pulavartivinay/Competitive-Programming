Question Link: https://practice.geeksforgeeks.org/problems/longest-consecutive-1s-1587115620/1

Solution:

int maxConsecutiveOnes(int N)
{
    // code here
    int ans = 0;
    int count = 0;
    for(int i=0;i<32;i++)
    {
        if(N & (1 << i)) count++;
        else
        {
            ans = max(ans, count);
            count = 0;
        }
    }
    return ans;
}
