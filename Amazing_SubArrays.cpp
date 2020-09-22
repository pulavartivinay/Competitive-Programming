You are given a string S, and you have to find all the amazing substrings of S.
Amazing Substring is one that starts with a vowel (a, e, i, o, u, A, E, I, O, U).
Input
Only argument given is string S.
Output
Return a single integer X mod 10003, here X is number of Amazing Substrings in given string.
Constraints
1 <= length(S) <= 1e6
S can have special characters
Example
Input
    ABEC
Output
    6
Explanation
	Amazing substrings of given string are :
	1. A
	2. AB
	3. ABE
	4. ABEC
	5. E
	6. EC
	here number of substrings are 6 and 6 % 10003 = 6.
  
  Solution:
    int Solution::solve(string A) {
    int li = 0;
    int n = A.size();
    for(int i=0;i<A.size();i++)
    {
        if(A[i] == 'a' or A[i] == 'e' or A[i] == 'i' or A[i] == 'o' or A[i] == 'u' or A[i] == 'A' or A[i] == 'E' or A[i] == 'I' or A[i] == 'O' or A[i] == 'U')
        {
            li = li + (n-i);
        }
    }
    return (li%10003);
}
