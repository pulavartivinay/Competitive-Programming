Question Link: https://practice.geeksforgeeks.org/problems/reverse-bits3556/1

Solution:

long long reversedBits(long long X) {
    // code here
    long long int ans = 0;
    for(int i=0;i<32;i++)
    {
        if(X & (1 << i)) ans += pow(2,31-i);
    }
    return ans;
}
