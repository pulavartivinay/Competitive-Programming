// Determine whether an integer is a palindrome. Do this without extra space.

// A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
// Negative numbers are not palindromic.

// Example :

// Input : 12121
// Output : True

// Input : 123
// Output : False

Solution:
  int Solution::isPalindrome(int A) {
    string b = to_string(A);
    string c = b;
    reverse(c.begin(),c.end());
    if(b == c)
    {
        return 1;
    }
    return 0;
}
