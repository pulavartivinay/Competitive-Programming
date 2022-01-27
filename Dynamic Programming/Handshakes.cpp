Question Link: https://practice.geeksforgeeks.org/problems/handshakes1303/1

Solution:

int count(int N)
{
    // code here
    if(N == 0) return 0;
    else if(N == 2) return 1;
    else
    {
        int ans = 2*count(N-2);
        for(int i=3;i<=(N-2);i=i+2)
        {
            ans += count(i-1)*count(N-i-1);
        }
        return ans;
    }
}
