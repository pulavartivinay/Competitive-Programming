// Reverse the bits of an 32 bit unsigned integer A.
// Problem Constraints
// 0 <= A <= 2**32
// Input Format
// First and only argument of input contains an integer A.
// Output Format
// Return a single unsigned integer denoting the decimal value of reversed bits.
// Example Input
// Input 1:
//  0
// Input 2:
//  3
// Example Output
// Output 1:
//  0
// Output 2:
//  3221225472
// Example Explanation
// Explanation 1:
//         00000000000000000000000000000000
// =>      00000000000000000000000000000000
// Explanation 2:
//         00000000000000000000000000000011    
// =>      11000000000000000000000000000000

Solution:
  #include<bits/stdc++.h>
unsigned int Solution::reverse(unsigned int A) {
    string s = bitset<32> (A).to_string();
    unsigned int li = 0;
    int n = s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i] == '1')
        {
            li = li + pow(2,i);
        }
    }
    return li;
}
