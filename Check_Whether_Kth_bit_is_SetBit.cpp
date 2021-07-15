Question Link: https://practice.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1

Solution:

bool checkKthBit(int n, int k)
{
    // Your code here
    // It can be a one liner logic!! Think of it!!
    if(n & (1 << k)) return 1;
    else return 0;
}
