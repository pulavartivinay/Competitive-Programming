Question Link: https://practice.geeksforgeeks.org/problems/binary-number-to-decimal-number3525/1

Solution:

int binary_to_decimal(string str)
{
    // Code here.
    int k = str.length();
    int ans = 0;
    for(int i=k-1;i>=0;i--)
    {
        if(str[i] == '1') ans += pow(2,k-1-i);
    }
    return ans;
}
