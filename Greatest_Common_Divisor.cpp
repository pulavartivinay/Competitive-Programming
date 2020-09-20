Given 2 non negative integers m and n, find gcd(m, n)
GCD of 2 integers m and n is defined as the greatest integer g such that g is a divisor of both m and n.
Both m and n fit in a 32 bit signed integer.
Example:
m : 6
n : 9
GCD(m, n) : 3 
 NOTE : DO NOT USE LIBRARY FUNCTIONS
 
 Solution:
  int Solution::gcd(int A, int B) {
    int a,b;
    if(A == 0 and B == 0)
    {
        return 0;
    }
    else if(A == 0)
    {
        return B;
    }
    else if(B == 0)
    {
        return A;
    }
    
    
    if(A > B)
    {
        a = A;
        b = B;
    }
    else
    {
        a = B;
        b = A;
    } // a be largest and b be smallest
    if(a%b == 0)
    {
        return b;
    }
    return gcd(a%b,b);
}
  
