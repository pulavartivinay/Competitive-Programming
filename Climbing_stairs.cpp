Question Link: https://leetcode.com/problems/climbing-stairs/

Solution:

int DP(int n, vector<int>& store)
{
    if(n <= 0) return 0;
    if(store[n] != 0) return store[n];

    if(n == 1)
    {
        store[1] = 1;
        return store[1];
    }
    else if(n == 2)
    {
        store[2] = 2;
        return store[2];
    }
    else
    {
        store[n] = DP(n-1, store) + DP(n-2, store);
        return store[n];
    }
}
int climbStairs(int n) {
    vector<int> store(46,0);
    return DP(n, store);    
}
