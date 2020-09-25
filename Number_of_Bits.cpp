// Write a function that takes an unsigned integer and returns the number of 1 bits it has.
// Example:
// The 32-bit integer 11 has binary representation
// 00000000000000000000000000001011
// so the function should return 3.

Solution:
  #include <bits/stdc++.h> 
int Solution::numSetBits(unsigned int A) {
    string s = bitset<64> (A).to_string();
    int n = s.size();
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(s[i] == '1')
        {
            count = count + 1;
        }
    }
    return count;
}
