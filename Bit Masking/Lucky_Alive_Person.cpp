Question Link: https://practice.geeksforgeeks.org/problems/lucky-alive-person-in-a-circle1229/1#

Solution:

int find(int N)
{
    // code here
    int n1 = 0;
    int end = -1;
    for(int i=0;i<32;i++)
    {
        if(N & (1 << i)) end = i;
    }
    for(int i=0;i<=end;i++)
    {
        if(N & (1 << i)) continue;
        else n1 += pow(2,i);
    }
    return (N-n1);
}
