Question Link: https://practice.geeksforgeeks.org/problems/cutted-segments1642/1

Solution:

int cutHelper(int n, int x, int y, int z, vector<int>& v)
{
    if(n == 0) // edge case
    {
        return 0;
    }
    if(v[n] != -1)
    {
        return v[n];
    }
    int a=INT_MIN,b=INT_MIN,c=INT_MIN;
    if(n >= x)
    {
        a = 1 + cutHelper(n-x, x, y, z, v);
    }
    if(n >= y)
    {
        b = 1 + cutHelper(n-y, x, y, z, v);
    }
    if(n >= z)
    {
        c = 1 + cutHelper(n-z, x, y, z, v);
    }
    v[n] = max(max(a,b),c);
    return v[n];
}
int maximizeTheCuts(int n, int x, int y, int z)
{
    //Your code here
    vector<int> v (n+1, -1);
    int ans = cutHelper(n, x, y, z, v);
    if(ans < 0) return 0;
    return ans;
}
