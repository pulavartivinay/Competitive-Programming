Question Link: https://practice.geeksforgeeks.org/problems/xor-game2143/1

Solution:

int xorCal(int k)
{
    // code here
    if(k == 1) return 2;
    int a = k+1;
    int b = ceil(log2(a));
    if(a == pow(2,b)) return (a/2)-1;
    else return -1;
}
