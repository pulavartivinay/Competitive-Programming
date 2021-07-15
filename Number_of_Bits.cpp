Question Link: https://practice.geeksforgeeks.org/problems/set-bits0143/1

Solution:

int setBits(int N) {
    // Write Your Code here
    int ans = 0;
    for(int i=0;i<32;i++)
    {
        if(N & (1 << i)) ans++;
    }
    return ans;
}
