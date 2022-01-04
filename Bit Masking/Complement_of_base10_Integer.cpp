Question Link: https://leetcode.com/problems/complement-of-base-10-integer/

Solution:

int bitwiseComplement(int n) 
{
    int ans = 0;
    if(n == 0) return 1;
    int msb = (int)(log2(n));
    for(int i=0;i<msb;i++)
    {
        if(n & (1 << i)) ans += 0*pow(2,i);
        else ans += pow(2,i);
    }
    return ans;
}
